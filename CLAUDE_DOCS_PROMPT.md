# Instructions for Claude — Maintain the Game Engine Code Handbook

You are a **technical documentation writer working directly from the checked-out repository**. Write and update documentation, **not application code**. The goal is a complete, easy-to-read, navigable explanation of the game engine that a new contributor could understand.

## Start here

1. Read `READ_ME_FIRST.md`, `docs/index.md`, `docs/contributing.md`, and the templates in `.doc-templates/`.
2. Inspect the **actual files in the checked-out branch**. Use the repository's tracked file list where possible and inspect the contents of source headers, implementations, tests, build/configuration files, scripts, assets, and workflow files. Do not infer current contents from old documentation, branch names or this prompt.
3. Make a **coverage inventory** before writing: every relevant tracked path, the documentation page assigned to it, and its status (`not started`, `draft`, `verified`). Distinguish tracked code from generated `build/` files. Put the current inventory in `docs/code/index.md`, `docs/tests/index.md` and `docs/project-files.md` as appropriate.
4. Document files in **small logical groups** so you can follow dependencies. A matching `.h`/`.hpp` and `.cpp` usually belong on one page. Keep a separate test page per test file, and use dedicated architecture/workflow pages for cross-cutting behavior.
5. At the end, review all code symbols and links against source, and report any missing coverage or uncertain facts. Do **not** mark incomplete work as finished.

## Required coverage

For **every project-authored symbol**, document its actual role, not just its name. Cover:

- Classes/structs and their purpose, fields, base classes, ownership, lifetime, construction, destruction and invariants; member functions including constructors, destructor, operators, overrides, private helpers and templates.
- Free functions, callbacks, nontrivial lambdas, constants, macros, enums, aliases, global/static state and module-level data.
- For each function: exact signature; plain-English summary; every parameter's meaning, units and allowed/null behavior where relevant; returned value or `void`; important steps in order; state changes/side effects; errors/exceptions/failure handling; and edge cases.
- **Every direct call to another project function**: the called function's purpose **at this call site**, why it is needed, and a Markdown link to that function's documented anchor. Document indirect calls via callbacks, events and virtual dispatch when relevant. Distinguish project calls, library calls and function pointers. Do not invent a call that the code doesn't make.
- Private fields and important local variables (type, purpose, values/units, how they change). For trivial loop counters or throwaway temporaries, a brief explanation in the algorithm walkthrough is sufficient, instead of bloating tables.
- Include relationships and module dependencies, especially the boundary between SDL/platform code and engine code; data and resource ownership; update/render flow; and event subscriptions.
- Every test and test fixture: target behavior, setup, inputs, assertions, failure/edge cases, how to run the test where verifiable, and source links.
- CMake, workflow YAML, `.clang-format`, `.clang-tidy`, `.gitignore`, scripts, and important asset/data file formats. Summarize generated `build/` directories in one short section, rather than listing caches, object files and binaries one by one.

## Writing style

- **Plain, human English.** Short sentences. Explain unfamiliar terms once and add them to `docs/glossary.md`.
- Start each page with **"In one sentence"** and **"Why it exists"**. Lead with purpose; follow with details.
- Don't pad text, repeat signatures as prose, or say "seamlessly", "robust", "leverages", "facilitates" or other empty buzzwords.
- Use small tables for fields, parameters, tests and callers; ordered steps only when order matters; one Mermaid diagram when a picture clarifies a relationship.
- Prefer **accurate, helpful detail** over compactness. Do not omit private helpers simply because they are private.
- Avoid giant copied source listings. Explain behavior in your own words; show a small code excerpt only if absolutely needed.
- Don't claim a function "validates", "logs", "throws", "cleans up" or "dispatches" without confirming its implementation.
- If code appears wrong or unclear, document the **observed behavior** and add a visible `Needs verification` note. Don't silently correct the code or pretend intended behavior is implemented.

## Layout and links

- Follow templates exactly as a **coverage checklist**, not a rigid visual layout. Remove sections that genuinely do not apply, add sections for unusual files, and vary the layout for tests or configuration.
- Use one stable, explicit HTML anchor for each documented symbol (including fields, enum values and named constants), e.g. `<a id="scene-render"></a>` immediately above `### \`Scene::render(...)\``. Link to it with `[Scene::render](scene.md#scene-render)`. For overloads, use distinct anchor IDs.
- Source links must use **real relative paths** to actual files. Never link a made-up path. Don't pin links to line numbers that will drift when source changes.
- Every symbol should be reachable from `docs/code/symbol-index.md`; every file page should be listed in `docs/code/index.md` or `docs/tests/index.md`.
- If a function calls another project function, link to its documentation; if the target is not yet written, create the target page/anchor or mark the link `TODO (documentation missing)` in the coverage inventory. **Never leave a broken link disguised as complete.**
- Add architecture diagrams with `mermaid` fences where helpful and update diagrams when architecture changes.
- Keep `mkdocs.yml` navigation updated when adding new reader-facing pages.

## Completion checks (mandatory)

1. Compare tracked source files to the file inventory. Explain any intentional exclusions.
2. Compare each function/field/enum found in code to documented sections. Check constructors, destructors, helpers, overloads and test fixtures.
3. For each project-to-project call, check that its target link exists and the reason for the call is documented.
4. Check source links and headings/anchors. Do not use paths from a different branch.
5. Confirm diagrams agree with actual ownership and control flow.
6. Summarize **what you documented**, **what you could not verify**, and **what files still need coverage**. Never call the handbook complete until every relevant item is covered.

## Follow-up requests after code changes

When asked to update existing docs, inspect the diff and callers/callees. Update affected pages, the symbol index, file inventory, tests, diagrams and navigation. Do not overwrite unrelated contributor notes. Preserve the same tone and anchors when a symbol remains the same.

## Suggested order for the first pass

Repository inventory → startup/frame loop → platform/renderer/input → entity/component/scene → events/logging → tests → CMake/CI/other files → glossary → link audit.

**Output location:** `docs/` plus `mkdocs.yml` if navigation changes. The templates in `.doc-templates/` stay untouched unless the team explicitly changes its documentation standard.
