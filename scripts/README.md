# N1 Script

This script helps me write boilerplate so I don't have to `mkdir` and `touch` the same directories and files every time I want to start an HTML project or C program.

The idea is have a script that can be called with:

```bash
n1script
```

The script should be able to accept arguments.
1. When called without any argument, the menu is shown.
2. When called with one argument:
    ```bash
    n1script i
    ```
    The script performs one of these operation:
    1. Generates the boilerplate.
    2. Insert the authoring header.
