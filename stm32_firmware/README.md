## Flashing the STM32

Run the following commands after installing `west` or sourcing the nix flake:

```bash
west init
west config manifest.path manifest
west update
west build urc_stm32_firmware --board=nucleo_g431kb
```
