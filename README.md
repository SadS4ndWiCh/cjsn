# 🎐 cjsn

Parse JSON with pure C.

## REPL

Currently it only supports the lexing step, returning all tokens from given JSON through stdin.

To test with large JSON files, ensure the JSON has no line break and pipe cat with it:

```sh
cat file.json | ./bin/repl
```

## Building

To build both test and repl, just runs:

```sh
make build
```
> Otherwise, `make test` or `make repl`
