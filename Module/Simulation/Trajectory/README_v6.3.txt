===================================================
BIRDY_TS: TRAJECTORY SOLVER, BIRDY's Ground Segment
===================================================
(see GSE-001.sce's header for details)
Project Ref.: GSE-001
Date: 16-feb-2015
Version 6.3
CL=1
Authors: Audrey Porquet (until v6),
         Boris Segret (from v6.1)

GSE-001.sce is the main program. See GSE-001.sce's header for all required subprograms and their versions.
See Tech.Note GSE-002.pdf for details and GSE-001.pdf for the standard user manual.
This version 6.3 is functional for parallel processing.
The delivery contains (see headers for version numbers):
  GSE-001.sce
  GSE-001_inputs (template).sce (test file)
  GSE-001_settings.sce
  GSE-001_outputs.sce
  GSE-001_results.sce
  GSE-001_functions.sce
  FreeMotion_Engine.sce
  BIRDY_TS_batch
  truc_05_inputs (test file)
  truc_10_inputs (test file)
  truc_15_inputs (test file)
  GL-01_sun_58122.xyzv (test file)
  GSE-002.pdf
  GSE-001.pdf, GSE-001.odt

Run in Scilab from the local directory:
---------------------------------------
(copy "GSE-001_inputs (template).sce" into "GSE-001_inputs.sce")
  exec('GSE-001.sce',-1);

Run in the command line from the local directory:
-------------------------------------------------
(GSE-001_inputs.sce must not be present)
  nohup nice -n 15 ./BIRDY_TS_batch &

SciLab program >=5.4 is required, with CNES' CelestLab >=3.0.0.

