# Competitive Programming — C++

An organized archive of C++ solutions, contest practice, and reusable algorithm notes. The repository shows ongoing practice across international online judges and Taiwanese programming contests.

## What is included

- CSES, AtCoder, Codeforces, Library Checker, and Online Judge solutions
- USACO and JOI practice, grouped by season/year and division where known
- Taiwanese contest collections including TOI, NHSPC, APCS, NTU CPC, IOICamp, and ZeroJudge
- `Local Practice/` for locally named exercises whose original platform could not be verified
- `structure.cpp` as a reusable geometry/DSU template kept at the repository root

## Repository structure

```text
.
├── Atcoder/
├── CSES/
├── codeforce/
├── IOICamp/
├── JOI/
├── Local Practice/
├── NHSPC (NewTaipei)/
├── OnlineJudge/
├── USACO/
├── toij/
├── ntucpc/
└── structure.cpp
```

Files retain contest IDs and problem titles where available. Folders were normalized when the source collection made the contest identity clear—for example, NHSPC files are grouped under `NHSPC (NewTaipei)/`, and IOICamp practice is separated from NTU CPC.

## Compile and run

Most solutions are standalone programs using standard input and output. A typical local build is:

```bash
g++ -std=c++17 -O2 -Wall -Wextra "path/to/solution.cpp" -o solution
./solution < input.txt
```

Some files use GNU C++ extensions or require an accompanying grader/header for a special judge. Check the surrounding folder before compiling those files.

## Scope and status

This is a learning archive, not a claim that every file is accepted, complete, or optimized. The public copy excludes local IDE settings, competitive-programming helper metadata, credentials, compiled binaries, and other machine-specific artifacts. Duplicate root copies were removed when a more clearly classified version already existed; `structure.cpp` was intentionally retained as requested.
