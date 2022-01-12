// PCH.H: Common header file

#ifndef PCH_H
#define PCH_H
#include <Printers.hpp>
#include <Registry.hpp>
//#include <Forms.hpp>
//#include <Filectrl.hpp>


// C RTL headers
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream.h>
#include <fstream.h>


// project headers not likely to change
//#include "StrmStrg.h"
#include "TGAbout.h"

// project headers are pre-compiled
// only if PRECOMPILE_ALL_TG is defined
#ifdef PRECOMPILE_ALL

#ifndef TGH
#include "tg.h"
#endif

//#ifndef TGParentH
//#include "TGParent.h"
//#endif

//#ifndef TGDiagrmH
//#include "TGDiagrm.h"
//#endif

//#ifndef GraphicsH
//#include "graphics.h"
//#endif
#ifndef TGraphicH
#include "TGraphic.h"
#endif

//#ifndef TGHelpH
//#include "TGHelp.h"
//#endif

#ifndef TGUtilsH
#include "TGUtils.h"
#endif

//#ifndef TGStyleH
//#include "TGStyle.h"
//#endif

//#ifndef TGXaxesH
//#include "TGXaxes.h"
//#endif

//#ifndef TGYaxesH
//#include "TGYaxes.h"
//#endif

//#ifndef TGDatesH
//#include "TGDates.h"
//#endif

//#ifndef TGDateFrmH
//#include "TGDatFrm.h"
//#endif

//#ifndef TGGraphH
//#include "TGGraph.h"
//#endif

//#ifndef TGZoneOpH
//#include "TGZoneOp.h"
//#endif

//#ifndef TGGrpFrmH
//#include "TGGrpFrm.h"
//#endif

//#ifndef TGGroupsH
//#include "TGGroups.h"
//#endif

//#ifndef TGMarkerH
//#include "TGMarker.h"
//#endif

//#ifndef TGPDendH
//#include "TGPDend.h"
//#endif

//#ifndef TGPLithH
//#include "TGPLith.h"
//#endif

//#ifndef TGPrintH
//#include "TGPrint.h"
//#endif

//#ifndef TGTextH
//#include "TGText.h"
//#endif

//#ifndef TGTxtOutH
//#include "TGTxtOut.h"
//#endif

//#ifndef TGTxtFrmH
//#include "TGTxtFrm.h"
//#endif

//#ifndef TGtgfioH
//#include "Tgtgfio.h"
//#endif

//#ifndef TGtgwioH
//#include "TGtgwio.h"
//#endif

//#ifndef TGYaxisH
//#include "TGYaxis.h"
//#endif

//#ifndef TGZoneH
//#include "TGZone.h"
//#endif

//#ifndef TGZoomH
//#include "TGZoom.h"
//#endif

//#ifndef TGOrderH
//#include "TGOrder.h"
//#endif

//#ifndef TGColorsH
//#include "TGColors.h"
//#endif

//#ifndef TGLinWidH
//#include "TGLinWid.h"
//#endif

#endif
#endif


