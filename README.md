# zest-native-test

A test package for [zest](https://github.com/fuseraft/zest)'s native extension support. zest's end-to-end tests install it and call it on Linux, macOS and Windows.

It has two halves:

- `src/zest_native_test.c`, a [native extension](https://fuseraft.ai/kiwi/stdlib/native/) that registers `add`, `mul` and `platform`. `src/kiwi_ext.h` is a copy of the header from Kiwi's `sdk/c`.
- `zest_native_test.kiwi`, Kiwi code that calls the extension.

`kiwi.json` lists a binary for each platform, attached to each release. Pushing a `v*` tag runs the Release workflow, which builds the binaries and creates the release.

```sh
zest install fuseraft/zest-native-test
```

```kiwi
include ".zest/load.kiwi"

println zest_native_test::sum_squares(3, 4)   # 25
println zest_native_test::platform()          # linux-x64, osx-arm64, win-x64, ...
```

Requires Kiwi 1.6.2 or later.
