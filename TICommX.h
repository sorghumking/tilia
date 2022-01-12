//---------------------------------------------------------------------------

#ifndef TICommonH
#define TICommonH
//---------------------------------------------------------------------------

class ISOTOPESERIES
{
public:
  int NumberOfSamples;
  UnicodeString SamplingOrigin;
  UnicodeString SampleDistUnits;
  Variant SampleInterval;
  Variant TransectWidth;
  Variant DrillBitSize;
  UnicodeString SampledBiolMarker;
public:
  ISOTOPESERIES() { NumberOfSamples = 0; }
  ISOTOPESERIES(ISOTOPESERIES& ser) { NumberOfSamples = ser.NumberOfSamples;
	SamplingOrigin = ser.SamplingOrigin; SampleDistUnits = ser.SampleDistUnits;
	SampleInterval = ser.SampleInterval; TransectWidth = ser.TransectWidth;
	DrillBitSize = ser.DrillBitSize; SampledBiolMarker = ser.SampledBiolMarker;  }
};

//---------------------------------------------------------------------------
#endif

