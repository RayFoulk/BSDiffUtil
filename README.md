# BSDiff-Fork
Fork of Colin Percival's BSDiff Utility

# Primary Goals
Modifications to the original BSDiff utility in this repo are intended to:
* Serve as a quantifiable Penalty/Cost Function for a closed-loop feedback control system as part of a research project.
* Remain compatible with the BSDiff 4.3 format, outputting patches in parallel.

This will be accomplished by separating the main algorithm from the compression stage, and outputting some human-readable text.

# Secondary Goals & Ideas
* Examine usage of alternative compression algorithms as applied to the same purpose.
* Add getopts and a help page to adjust runtime behavior.
