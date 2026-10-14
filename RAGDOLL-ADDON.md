# Dab's Mod v3.11.0: ragdolls, dismemberment and aiming crosshair (revision 2)

Unofficial Windows 64-bit integration. Dab's Mod v3.11.0 is the base.
Ragdolls and dismemberment are ON by default. Original authors' credits and
licences are retained; see CREDITS.md, LICENSE and JOLT-LICENSE.txt.
OpenAI Codex made the integration and these fixes with AI assistance.
CE's README separately discloses Claude Opus 5.5 and Fable 5.1 assistance.

## Installing the update

Close the old game. Unpack the ZIP, then copy pd.x86_64.exe and its two DLLs
into a COPY of the folder you already play from. Keep your data, saves,
pd.ini, mods, cache, added-content and packs. Those are not in the ZIP.
This is an engine change; it cannot be loaded through Load Mods.

If starting from a new folder, copy your own pd.ntsc-final.z64 into data.
START.cmd can copy it from the standard existing Dab's download folder.
No ROM or other game assets are downloaded by the launcher.

## Options

- Options > Extended Options > Ragdolls & Dismemberment: both switches.
- Options > Extended Options > Game > Player 1 (or your chosen player):
  Crosshair Only While Aiming. Enable it to hide the hip-fire crosshair.
  It defaults to OFF and saves independently for each player as
  Game.PlayerN.CrosshairOnlyWhileAiming. Target tracking still updates.
- Further ragdoll settings save under [Ragdoll] in pd.ini.
  Strong hits/explosions can sever limbs; the default chance is 40%.

## Revision 2 fixes

- Converted stages above the title/menu ID range now advance physics using
  Dab's existing STAGE_IS_LEVEL check. Previously the death hook stopped the
  animation but the physics loop skipped these stages, freezing the body.
- Normal enemy firing is retained via the original func0f041a74 call.
  The early work/playtest executable omitted it; that is an obsolete build.
- The requested optional crosshair setting also covers GoldenEye's sight.

Only physics/dismemberment and their required hooks, plus the explicitly
requested crosshair option, are changed. CE's unrelated port fixes, audio,
player collision, new cheat, grabbing controls, guard investigation and death
camera are excluded. A normal official update can replace this custom exe.

## Validation and limits

Revision 2 compiled and linked with OpenGL and Vulkan enabled. Jolt's
self-test and original ntsc-final ROM startup passed. A local converted
GoldenEye Runway stage (ID 0x5e) loaded collision and exited normally.
A debugger-created GoldenEye guard ragdoll advanced for 30 frames: its
pelvis moved from y=-113.75 to y=-173.65, demonstrating that the converted
stage now steps physics. This is a focused movement check, not exhaustive
gameplay validation. The actual sight-rendering functions were also checked:
with the option enabled, hip-fire produced no sight commands; aiming did.

The user reported frozen corpses and non-firing guards in the obsolete early
test build. The revised stage check and restored firing call address those
identified defects. Full GoldenEye/XBLA/model-pack gameplay and replacement
mesh dismemberment still need testing. These remain unofficial builds.

Up to 256 ragdoll records are tracked; physics resource exhaustion falls back
to the existing death system. Dab's body settings are retained, and simulant
corpse ownership transfers its physics pose. Physics random choices use a
separate random stream.

## Building

Use Dab's existing MSYS2 MINGW64 instructions with CMake 3.20+ and the Unix
Makefiles generator. Jolt v5.6.0 is fetched automatically, or supply JOLT_DIR.
PD_PHYSICS=OFF excludes physics. No game files are included in the GitHub
source branch or source archive; the playable binary ZIP has no ROM or saves.
