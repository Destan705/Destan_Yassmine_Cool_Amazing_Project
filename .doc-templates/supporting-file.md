# [Config / Script / Asset / Build File] — Reference

> **Coverage:** Draft / Verified · **Source:** [`path/to/actual-file`](../../path/to/actual-file)

**In one sentence:** [What this file controls or supplies.]

**Why it exists:** [Where it fits in the build, development workflow or runtime.]

## At a glance

| Question | Answer |
| --- | --- |
| Who uses it? | [Tool, target, script or module] |
| When is it read or run? | [Configure/build/test/CI/runtime] |
| Inputs | [Variables, arguments, files, env vars, dependencies] |
| Outputs or side effects | [Generated target, copied assets, lint result, etc.] |

## Sections / settings / commands

| Item | Value or action | Why it matters | Related code/file |
| --- | --- | --- | --- |
| `[real setting or step]` | [What it does] | [Reason] | [Verified link] |

If it is a script: document each function, options, exit status and significant variables with the same completeness as the **source-file** template.

If it is a workflow: explain triggers, dependencies, jobs, order, actions, success conditions and failure paths.

If it is an asset/data format: explain file location, encoding, units, file naming, who creates it, who loads it, and what happens if it is missing.

## Important behavior

1. [Step, including conditional branches.]
2. [Step; explain why it's done.]

## Dependencies and caveats

[Platform requirements; directory assumptions; failure behavior; generated-vs-tracked distinctions; anything surprising.]

**Related:** [Other Files index](../project-files.md)
