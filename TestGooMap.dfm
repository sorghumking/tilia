object TestGoogleMapForm: TTestGoogleMapForm
  Left = 0
  Top = 0
  Caption = 'Test Google Maps'
  ClientHeight = 299
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object WebGMaps1: TWebGMaps
    Left = 0
    Top = 0
    Width = 635
    Height = 299
    Align = alClient
    APIKey = 'AIzaSyAjlZDXT0ZiuAjv4fJ89wbxJaA_iTZQTmc'
    Clusters = <>
    Markers = <>
    Polylines = <>
    Polygons = <>
    Directions = <>
    MapOptions.DefaultLatitude = 48.859040000000000000
    MapOptions.DefaultLongitude = 2.294297000000000000
    MapOptions.DisablePOI = True
    MapOptions.DisableTilt = True
    Routing.PolylineOptions.Icons = <>
    StreetViewOptions.DefaultLatitude = 48.859040000000000000
    StreetViewOptions.DefaultLongitude = 2.294297000000000000
    ControlsOptions.StreetViewControl.Visible = False
    MapPersist.Location = mplInifile
    MapPersist.Key = 'WebGMaps'
    MapPersist.Section = 'MapBounds'
    PolygonLabel.Font.Charset = DEFAULT_CHARSET
    PolygonLabel.Font.Color = clBlack
    PolygonLabel.Font.Height = -16
    PolygonLabel.Font.Name = 'Arial'
    PolygonLabel.Font.Style = []
    TabOrder = 0
    WeatherOptions.ShowInfoWindows = False
    Version = '2.9.9.0'
  end
end
