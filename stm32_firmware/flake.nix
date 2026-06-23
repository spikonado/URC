{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

    flake-utils.url = "github:numtide/flake-utils";

    zephyr.url = "github:zephyrproject-rtos/zephyr/v4.4.1";
    zephyr.flake = false;

    zephyr-nix.url = "github:adisbladis/zephyr-nix";
    zephyr-nix.inputs.nixpkgs.follows = "nixpkgs";
    zephyr-nix.inputs.zephyr.follows = "zephyr";
  };

  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
      zephyr,
      zephyr-nix,
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs { inherit system; };
        zephyrPkgs = zephyr-nix.packages.${system};
      in
      {
        formatter = pkgs.nixfmt-tree;

        devShells.default = pkgs.mkShell.override { stdenv = pkgs.clangStdenv; } {
          name = "urc_stm32_firmware";

          packages = with pkgs; [
            bun
            cmake
            commitlint
            gcc
            gh
            git
            git-lfs
            ninja
            prek
            prettier
            zephyrPkgs.sdkFull
            zephyrPkgs.pythonEnv
            zephyrPkgs.hosttools
          ];
        };
      }
    );
}
