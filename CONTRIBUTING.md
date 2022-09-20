# How to Contribute

- Pick a problem, and create a folder for it inside `articles\problems\your-folder-name`
- Now create a `index.md` file.
    - It should follow this structure.

```md
---
title: problem title
hide:
  - navigation
tags:
  - tag1
  - tag2
---

## Problem

- describe the problem here
- and more about it

### Input

- here you will give input and corresponding output
- you can also include a explanation

## Solutions

### Solution 1

- here you will explain the algorithm

-```cpp
{{ include_file('solution1.cpp') }}
-```

-```txt
{{ include_file('solution1.txt') }}
-```

### Solution 2

- here you will explain the algorithm

-```cpp
{{ include_file('solution2.cpp') }}
-```

-```txt
{{ include_file('solution2.txt') }}
-```

## References ans External Links

- <https://www.google.com>
```

- above the `-` is before the three backtick only to prevent creating a new code block
- only C++ code will be accepted
- the code should be formatted using the clang formatter
  and its configuration is in the base folder `.clang-format`
- images go in the `img` folder inside the folder you created.
- use comments, but not the obvious comments.
- use STL instead of older features.
