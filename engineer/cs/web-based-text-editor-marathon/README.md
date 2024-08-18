# Web-based text editor marathon series

This series is designed to be incrementally improved over a time span - thus, the "marathon" in the title. Starting from some very basic functional requirements, further functional/non-functional requirements are added over time to test the implementer's ability to build extensible software & adaptability to changing requirements.

## What you will learn

* Learn to build extensible software.
* Learn to adapt to changing requirements.
* Learn to benchmark & set observability points.
* Learn to identify performance bottleneck.
* Learn to make tradeoffs in software engineering.

## Starting requirements

The running theme of this series is a web-based text editor built using the [monaco editor](https://microsoft.github.io/monaco-editor/).

For the first week you'll build a webapp that looks like the following (the exact UI is not important):

![image](https://github.com/user-attachments/assets/01b8f28c-edb4-4954-a75e-2f018db7b6ea)

* Build a virtual file explorer that allows:
  * Adding/Removing files/folders.
  * Expanding/Collapsing a folder's content.
  * Setting a file as active.
* Build a file content editor using the [monaco editor](https://microsoft.github.io/monaco-editor/) that allows:
  * Showing the active file's content.
  * Editing the active file's content.
  * Auto-saving.

## Rules

Look at the subfolders `iteration-xx` for requirements added over the span of time.

The starting requirements described here will be deemed `iteration-00`.

If you're implementing `iteration-xx`, you're only allowed to peek at `iteration-{xx + 1}` to "foresee" the future in a limited way. You're not allowed to peek at further iterations.

Each iteration has a suite of testcases that your app must pass.

## Related tools & References

* Monaco editor: https://microsoft.github.io/monaco-editor/
* Edge performance devtool
* OpenTelemetry: https://opentelemetry.io/

## Keywords

Software engineering, Virtual filesystem, Webapp, Text editor, Extensibility, Performance, Observability
