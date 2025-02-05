{
  description = "C++ environment for NeetCode 150";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs";

  outputs = { self, nixpkgs }:
  let
    pkgs = nixpkgs.legacyPackages.x86_64-linux;
  in {
    devShells.x86_64-linux.default = pkgs.mkShell {
      nativeBuildInputs = [
        pkgs.clang_16
        pkgs.cmake
        pkgs.conan
        pkgs.ninja
        pkgs.ccls
        pkgs.gdb
        pkgs.lld
        pkgs.clang-tools
      ];

      shellHook = ''
        echo "C++ NeetCode environment loaded!"
        export CXX=clang++
        export CC=clang
      '';
    };
  };
}
