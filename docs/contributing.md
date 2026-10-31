# Keeping the Documentation Updated

**Write the explanation at the same time you change the code.** The point is to make the handbook useful next month, not to complete it once and forget it.

## When you add code

1. Add the file to the [code inventory](code/index.md) (or [test inventory](tests/index.md)).
2. Copy the appropriate template from `.doc-templates/` at the repo root. Create a reader-facing page in `docs/code/`, `docs/tests/`, or an appropriate section.
3. Explain all new symbols, including private helpers, fields, enum values, constants and meaningful locals.
4. Link **every project function called** and explain why. Add reverse `Used by` links when helpful.
5. Add every symbol to the [symbol index](code/symbol-index.md). Update architecture diagrams and [glossary](glossary.md) if needed.
6. Add the new page to `mkdocs.yml` navigation so it appears in the book sidebar. Keep links relative and verify them.
7. Mark the page **Verified** only after checking it against source on the current branch.

## When you modify or remove code

Update the function description, affected callers/callees, tests, source links, symbols, and diagrams. Remove obsolete claims and broken links. Keep anchors stable when the same symbol still exists; give renamed symbols new anchors and update old links.

## Documentation page style

- Begin with one sentence and the reason the file/class exists.
- Use everyday English; be specific about outcomes and ownership.
- Use tables for scan-friendly facts and steps for execution order.
- Use a Mermaid diagram only if it genuinely saves explanation.
- Don't paste entire files; a source link is better.
- Be clear about **what code does now**, not what a ticket says it will eventually do.
- Put unresolved questions under **Needs verification** rather than guessing.

## Templates

These files live at the repository root and are intended to be copied, not shown as reader-facing chapters:

- `.doc-templates/source-file.md` — classes, functions, variables, events, dependencies.
- `.doc-templates/test-file.md` — fixtures and each test.
- `.doc-templates/supporting-file.md` — scripts, CMake, workflows, configuration, assets.
- `.doc-templates/workflow.md` — ownership, call paths and Mermaid diagrams.

To ask Claude to handle this, give it `CLAUDE_DOCS_PROMPT.md` from the repository root together with the checked-out repo.
