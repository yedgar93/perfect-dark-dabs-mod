# Dab's Mod v3.11.0 — ragdolls and dismemberment add-on

Windows 64-bit build based on Dab's Mod v3.11.0. Ragdolls and dismemberment
are enabled by default. All existing Dab's Mod features and settings remain.

## Play

Unpack the ZIP into a new folder. Copy your own `pd.ntsc-final.z64` into
`data/`, then run `pd.x86_64.exe`. To retain your existing progress/settings,
copy your existing saves and `pd.ini` into this folder, or put the executable
and its DLLs into a separate copy of your current Dab's Mod folder.

Options > Extended Options > Ragdolls & Dismemberment has two switches.
Strong weapon hits and explosions can sever limbs (default chance: 40%).
Further physics settings are under `[Ragdoll]` in `pd.ini` after first exit.
Dab's Bodies / Body Time / Bodies Drawn settings continue to apply.

This is an engine add-on delivered as a replacement executable. It cannot be
loaded as a data-only mod through Load Mods. A normal official update may
replace this custom executable; retain this ZIP if using Check for Updates.

The existing audio pipeline, input, camera, cheats, AI, renderer and player
collision are retained. CE's grab mechanic, Deadly Punch cheat, death camera,
guard body investigation, clip-check player collision and unrelated port
fixes are excluded. NPC knockout bodies also use ragdoll physics.
Physics uses a separate random stream so cosmetic reactions do not consume
the existing AI/weapon random sequence. Up to 256 ragdoll bodies are tracked;
if slots run out, subsequent deaths use Dab's existing animation system.

## Attribution and AI disclosure

Read `CREDITS.md`, `LICENSE` and `JOLT-LICENSE.txt`. The integration used
OpenAI Codex, and the CE source project discloses Claude Opus 5.5 and Fable 5.1
assistance. Original authors retain credit for their respective work.

## Build source

Use Dab's existing MSYS2 build instructions, with CMake 3.20+ for Jolt.
The CMake configuration downloads Jolt v5.6.0 automatically, or accepts
`-DJOLT_DIR=/path/to/JoltPhysics`. `-DPD_PHYSICS=OFF` excludes physics.
Use a MINGW64 shell and the Unix Makefiles generator on Windows.

## Validation

Windows 64-bit build completed with GCC 16.2 and Jolt v5.6.0; both
OpenGL and Vulkan were included. Local startup with an original ntsc-final
ROM passed the Jolt self-test and built the level collision successfully.
An 80-simulant 7,200-frame startup/stability run exited normally. That run
preceded the final change enabling simulant ragdolls, so it is not evidence
of simulant ragdoll or dismemberment correctness. The final source compiled
and linked successfully. The user reported successful local gameplay.
GoldenEye conversions, XBLA replacement meshes and other model packs remain
unverified; XBLA dismemberment seams may need additional adaptation. No ROM or other copyrighted game assets are included in the ZIP.
