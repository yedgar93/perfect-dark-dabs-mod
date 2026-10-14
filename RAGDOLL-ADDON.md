# Dab's Mod + Chesluk Physics â€” Yedgar Hybrid

Unofficial integration for Jon / yedgar93. Windows 64-bit, revision 7.
Base: DabDavis's official Dab's Mod v3.14.0 release, commit
90c8622e74b35be669d60d177effc6d7d2d7621c.

Chesluk-Industries's CE supplies ragdolls, dismemberment and body dragging.
Jon / yedgar93 requested and directed the integration and provides gameplay
testing. OpenAI Codex performed integration and compatibility work with AI
assistance. All original authors retain credit; see CREDITS.md and licences.
This is an unofficial derivative, without a claim of upstream endorsement.

## Install into your existing game

Close the game. Extract this ZIP and copy these three files into the folder
containing the executable you normally launch, replacing its existing copies:

- pd.x86_64.exe
- SDL2.dll
- zlib1.dll

Keep your existing data, added-content, mods, model-packs, texture-packs,
cache, pd.ini and saves. The ZIP contains no ROMs, game assets or saves.
Keep the included credits and licences alongside the executable.
This is an engine add-on. Dab's Load Mods page cannot load engine code.
It can be removed by restoring the official executable. The ordinary
in-game updater can also replace this custom executable with an official one.

## Body dragging

Options > Extended Options > Ragdolls & Dismemberment:

- Ragdolls, Dismemberment and Body Dragging (Hold Use) are all enabled by default.
- On the first launch of revision 5, all three are enabled once even if the
  previous settings file had them off. RepackDefaultsVersion=1 records this
  upgrade, and any later choices you make in the menu remain saved.
- Drag Strength controls the pulling force (default 1.20x).

Look at a nearby corpse and hold your configured Use button (E by default
on keyboard; controller binding depends on your control layout). Walk back
or move the view to pull it. Release Use to drop it. This uses CE's original
physics pulling code and works in solo/co-op; Combat Simulator dragging is
disabled as in CE. Characters and detached pieces remain physics driven.
Normal doors and switches take priority over acquiring a body. The acquired
drag consumes that Use press, including release, to prevent incidental
reload/activation or classic-control weapon-function changes.

Only body dragging is enabled here; CE's object-grab acquisition is excluded.
The source retains inert optional CE helpers. Player collision, death camera,
body investigation, held-body shields, CE's unrelated audio/port fixes and
new cheat are not enabled. Dab's crosshair controls and player-config layout
remain those of v3.14.0, with no added aiming-only crosshair option.

## Build and checks

Built from the exact v3.14.0 release tag with the integration applied, using
GCC 16.2, CMake, Jolt v5.6.0 and the stable update channel. OpenGL and Vulkan
are enabled. The build compiled and linked successfully.

The preceding revision 4 build started the original ntsc-final ROM and exited normally at a specified frame,
and Jolt's self-test passed. On converted GoldenEye Runway (stage 0x5e), a
debugger-created guard ragdoll moved over 30 frames, from pelvis y=-109.50
to y=-164.57. This confirms that the converted-stage physics loop advances.

A focused revision 4 debugger check acquired a body, issued 27 calls to the CE pulling
function, consumed Use, released the body and respected the off switch.
The normal-interaction priority guard was exercised with an injected target.
That check does not establish ordinary-play dragging quality or real door
operation. Its short lift observation did not raise the pelvis; it is not
treated as proof of successful body movement under dragging. Gameplay testing
is left to Jon at his request; no further game runs are being performed.

Revision 5 changes only the feature defaults and their one-time settings
upgrade. It compiled and linked successfully; no further gameplay tests were
run, at Jon's request. CE's dismemberment damage threshold (2.0) and chance
(40%) are unchanged. Qualifying head/limb hits can cut; ordinary torso shots
require at least 50 damage to split the torso, and knockouts do not dismember.
Jon subsequently confirmed dismemberment in regular PD and reported ragdolls
and dismemberment working across modes. XBLA dismemberment visibly stretched
meshes across cuts. Revision 6 isolates skin weights to each connected body
piece and removes triangles crossing disconnected pieces, for all HD drawing
passes. Severed HD bodies use a per-frame CPU pose; shared meshes and living
characters retain their existing rendering path. Corpse room/cleanup behavior
is unchanged. This addresses stretching, not multiplayer corpse retention.

The startup screen identifies this as Dab's Mod + Chesluk Physics and Yedgar
Hybrid v3.14.0 r6, reducing the value font when necessary to fit its column.
Original Rare/4J notices and full contributor credits are retained.

The r6 Windows build compiled and linked. Synthetic mesh checks passed for
piece-weight grouping, normalization, nested cuts, crossing-triangle rejection
and invalid indices. No gameplay runs were performed for r6. Jon must verify
clean separation on fresh XBLA/GoldenEye corpses; seam appearance and all
replacement-model variations are not yet confirmed.

Original v3.14.0 sight.c and types.h are unchanged. Normal enemy firing retains
the original func0f041a74 call. This supersedes the old v3.11.0 test packages.

Please test pickup, dragging while moving, release and strength; normal door
and switch use; absence of incidental reload/weapon-mode changes; live guards
shooting; and dead guards falling. Test original PD and GoldenEye/XBLA content.
Replacement meshes and dismemberment seams need their own gameplay checks.
The focus checks do not establish compatibility with every mission or pack.

Up to 256 ragdoll records are tracked. Resource exhaustion falls back to the
existing death system. Dab's retained-body handoff is adapted to keep physics
ownership, and its pose cache yields to ragdolls. Physics randomness uses a
separate stream from gameplay randomness.

## Source and rebuilding

Only source-code and credit/documentation changes are published to GitHub.
No ROMs, executables, saves, textures, sound files or XBLA packages are uploaded.
The accompanying source patch is applied to the official v3.14.0 checkout
with git apply --index. Build using Dab's MSYS2 MINGW64 instructions, CMake
3.20+ and Jolt v5.6.0. Jolt is fetched automatically, or set JOLT_DIR to a
local checkout. Pass UPDATE_CHANNEL=stable. PD_PHYSICS=OFF omits physics.

## Revision 7: fitted XBLA cut rims

Jon's r6 gameplay test showed that piece separation worked but exposed jagged
HD triangle edges and oversized original-model caps. Revision 7 projects the
HD cut-rim vertices onto the severed joint plane, aligns duplicated vertices
across material/batch seams, and poses each rim rigidly in its own side's
joint frame. Cap fans use the retained HD boundary edges and the same posed
vertices; interior edges cancel. Prepared HD caps replace the original PD
caps for that body. Regular PD rendering, blood amount and corpse cleanup
remain unchanged. No blood/gore overhaul is included in this revision.

The startup now identifies revision 7. Windows x64 compilation/linking passed.
Synthetic checks covered axis-aligned and oblique plane projection, degenerate
planes, a fitted quad rim, cancellation of interior edges, and rejection of
cross-piece triangles, alongside the r6 connected-piece weight checks.
These do not establish the appearance of every real model: Jon must test
fresh PD XBLA and GoldenEye XBLA corpses, including single and multiple cuts,
dragging, reflections and fades. No r7 gameplay runs were performed.

This cleans the existing mesh seam; it does not introduce a general-purpose
triangle slicing engine or new gore artwork. OpenAI Codex implemented this
adaptation with AI assistance at Jon / yedgar93's direction. Original authors
retain their existing credits.
