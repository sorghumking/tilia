object NeotomaDataForm: TNeotomaDataForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'Get Neotoma Data'
  ClientHeight = 516
  ClientWidth = 784
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 193
    Height = 497
    Align = alLeft
    BevelOuter = bvNone
    Enabled = False
    TabOrder = 0
    object cxComboBox1: TcxComboBox
      Left = 8
      Top = 22
      Properties.DropDownListStyle = lsEditFixedList
      Properties.OnChange = cxComboBox1PropertiesChange
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 0
      OnKeyDown = cxComboBox1KeyDown
      Width = 178
    end
    object cxLabel1: TcxLabel
      Left = 8
      Top = 4
      Caption = 'Dataset Type:'
    end
    object cxTextEdit1: TcxTextEdit
      Left = 8
      Top = 68
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 1
      Width = 178
    end
    object cxLabel2: TcxLabel
      Left = 8
      Top = 50
      Caption = 'Site Name (use % for wildcard):'
    end
    object FlowPanel1: TFlowPanel
      Left = 32
      Top = 390
      Width = 129
      Height = 51
      BevelOuter = bvNone
      TabOrder = 10
      object cxButton1: TcxButton
        Left = 0
        Top = 0
        Width = 128
        Height = 25
        Caption = 'Search'
        LookAndFeel.Kind = lfOffice11
        OptionsImage.ImageIndex = 0
        OptionsImage.Images = cxImageList1
        TabOrder = 0
        OnClick = cxButton1Click
      end
      object cxButton2: TcxButton
        Left = 0
        Top = 25
        Width = 64
        Height = 25
        Caption = 'Reset'
        LookAndFeel.Kind = lfOffice11
        OptionsImage.ImageIndex = 2
        OptionsImage.Images = cxImageList1
        TabOrder = 1
        OnClick = cxButton2Click
      end
      object cxButton3: TcxButton
        Left = 64
        Top = 25
        Width = 64
        Height = 25
        Caption = 'Cancel'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 2
        OptionsImage.ImageIndex = 1
        OptionsImage.Images = cxImageList1
        TabOrder = 2
        OnClick = cxButton2Click
      end
    end
    object cxLabel3: TcxLabel
      Left = 8
      Top = 96
      Caption = 'First Geopolitical Division:'
    end
    object cxComboBox2: TcxComboBox
      Left = 8
      Top = 114
      Properties.DropDownListStyle = lsEditFixedList
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 2
      OnClick = cxComboBox2Click
      Width = 178
    end
    object cxComboBox3: TcxComboBox
      Left = 8
      Top = 160
      Enabled = False
      Properties.DropDownListStyle = lsEditFixedList
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 3
      OnClick = cxComboBox3Click
      Width = 178
    end
    object cxLabel4: TcxLabel
      Left = 8
      Top = 142
      Caption = 'Second Geopolitical Division:'
      Enabled = False
    end
    object cxComboBox4: TcxComboBox
      Left = 8
      Top = 206
      Enabled = False
      Properties.DropDownListStyle = lsEditFixedList
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 4
      Width = 178
    end
    object cxLabel5: TcxLabel
      Left = 8
      Top = 188
      Caption = 'Third Geopolitical Division:'
      Enabled = False
    end
    object cxComboBox5: TcxComboBox
      Left = 8
      Top = 252
      Enabled = False
      Properties.DropDownListStyle = lsEditFixedList
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 5
      Width = 178
    end
    object cxLabel6: TcxLabel
      Left = 8
      Top = 234
      Caption = 'Forth Geopolitical Division:'
      Enabled = False
    end
    object cxComboBox6: TcxComboBox
      Left = 8
      Top = 298
      Enabled = False
      Properties.DropDownAutoWidth = False
      Properties.DropDownListStyle = lsEditFixedList
      Properties.DropDownSizeable = True
      Properties.DropDownWidth = 178
      Properties.Sorted = True
      Properties.OnChange = cxComboBox6PropertiesChange
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 6
      OnKeyDown = cxComboBox6KeyDown
      Width = 154
    end
    object cxLabel8: TcxLabel
      Left = 8
      Top = 280
      Caption = 'Principal Investigator:'
    end
    object cxComboBox7: TcxComboBox
      Left = 8
      Top = 344
      Enabled = False
      Properties.DropDownAutoWidth = False
      Properties.DropDownListStyle = lsEditFixedList
      Properties.DropDownSizeable = True
      Properties.DropDownWidth = 178
      Properties.Sorted = True
      Properties.OnEditValueChanged = cxComboBox7PropertiesEditValueChanged
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 7
      OnKeyDown = cxComboBox7KeyDown
      Width = 154
    end
    object cxLabel9: TcxLabel
      Left = 8
      Top = 326
      Caption = 'Author:'
    end
    object cxButton4: TcxButton
      Left = 163
      Top = 297
      Width = 23
      Height = 23
      Hint = 'Download PIs from Neotoma'
      HelpType = htKeyword
      LookAndFeel.Kind = lfFlat
      LookAndFeel.NativeStyle = True
      OptionsImage.ImageIndex = 3
      OptionsImage.Images = cxImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 17
      OnClick = cxButton4Click
    end
    object cxButton5: TcxButton
      Left = 163
      Top = 343
      Width = 23
      Height = 23
      Hint = 'Download authors from Neotoma'
      LookAndFeel.Kind = lfFlat
      LookAndFeel.NativeStyle = True
      OptionsImage.ImageIndex = 3
      OptionsImage.Images = cxImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 18
      OnClick = cxButton5Click
    end
    object FlowPanel2: TFlowPanel
      Left = 21
      Top = 460
      Width = 150
      Height = 25
      AutoSize = True
      AutoWrap = False
      BevelOuter = bvNone
      TabOrder = 19
      Visible = False
      object cxButton6: TcxButton
        Left = 0
        Top = 0
        Width = 75
        Height = 25
        Caption = 'Old Sites'
        LookAndFeel.NativeStyle = True
        SpeedButtonOptions.GroupIndex = 1
        TabOrder = 0
        OnClick = cxButton6Click
      end
      object cxButton7: TcxButton
        Left = 75
        Top = 0
        Width = 75
        Height = 25
        Caption = 'New Sites'
        SpeedButtonOptions.GroupIndex = 1
        SpeedButtonOptions.Down = True
        TabOrder = 1
        OnClick = cxButton7Click
      end
    end
  end
  object Panel2: TPanel
    Left = 193
    Top = 0
    Width = 591
    Height = 497
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 2
    object WebGMaps1: TWebGMaps
      Left = 0
      Top = 137
      Width = 591
      Height = 360
      Align = alBottom
      APIKey = 'AIzaSyAjlZDXT0ZiuAjv4fJ89wbxJaA_iTZQTmc'
      Clusters = <>
      Markers = <>
      Polylines = <>
      Polygons = <>
      Directions = <>
      MapOptions.ZoomMap = 1
      MapOptions.MapType = mtTerrain
      MapOptions.DefaultLatitude = 45.000000000000000000
      MapOptions.DefaultLongitude = 2.294297000000000000
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
      OnMarkerClick = WebGMaps1MarkerClick
    end
    object AdvColumnGrid1: TAdvColumnGrid
      Left = 0
      Top = 0
      Width = 591
      Height = 131
      Cursor = crDefault
      Align = alTop
      ColCount = 6
      DrawingStyle = gdsClassic
      FixedCols = 0
      RowCount = 4
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
      ScrollBars = ssBoth
      TabOrder = 1
      Visible = False
      HoverRowCells = [hcNormal, hcSelected]
      OnHoverButtonClick = AdvColumnGrid1HoverButtonClick
      ActiveCellFont.Charset = DEFAULT_CHARSET
      ActiveCellFont.Color = clWindowText
      ActiveCellFont.Height = -11
      ActiveCellFont.Name = 'Tahoma'
      ActiveCellFont.Style = [fsBold]
      ColumnHeaders.Strings = (
        'Site ID'
        'Site Name'
        'Latitude'
        'Longitude'
        'Pol Div 1'
        'Pol Div 2')
      ColumnSize.Stretch = True
      ColumnSize.StretchAll = True
      ControlLook.FixedGradientHoverFrom = clGray
      ControlLook.FixedGradientHoverTo = clWhite
      ControlLook.FixedGradientDownFrom = clGray
      ControlLook.FixedGradientDownTo = clSilver
      ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
      ControlLook.DropDownHeader.Font.Color = clWindowText
      ControlLook.DropDownHeader.Font.Height = -11
      ControlLook.DropDownHeader.Font.Name = 'Tahoma'
      ControlLook.DropDownHeader.Font.Style = []
      ControlLook.DropDownHeader.Visible = True
      ControlLook.DropDownHeader.Buttons = <>
      ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
      ControlLook.DropDownFooter.Font.Color = clWindowText
      ControlLook.DropDownFooter.Font.Height = -11
      ControlLook.DropDownFooter.Font.Name = 'Tahoma'
      ControlLook.DropDownFooter.Font.Style = []
      ControlLook.DropDownFooter.Visible = True
      ControlLook.DropDownFooter.Buttons = <>
      Filter = <>
      FilterDropDown.Font.Charset = DEFAULT_CHARSET
      FilterDropDown.Font.Color = clWindowText
      FilterDropDown.Font.Height = -11
      FilterDropDown.Font.Name = 'Tahoma'
      FilterDropDown.Font.Style = []
      FilterDropDown.TextChecked = 'Checked'
      FilterDropDown.TextUnChecked = 'Unchecked'
      FilterDropDownClear = '(All)'
      FilterEdit.TypeNames.Strings = (
        'Starts with'
        'Ends with'
        'Contains'
        'Not contains'
        'Equal'
        'Not equal'
        'Larger than'
        'Smaller than'
        'Clear')
      FixedColWidth = 98
      FixedRowHeight = 22
      FixedFont.Charset = DEFAULT_CHARSET
      FixedFont.Color = clWindowText
      FixedFont.Height = -11
      FixedFont.Name = 'Tahoma'
      FixedFont.Style = [fsBold]
      FloatFormat = '%.2f'
      GridImages = cxImageList1
      HoverButtons.Enabled = True
      HoverButtons.Buttons = <
        item
          ImageIndex = 3
        end>
      HoverButtons.Position = hbRightFromColumnLeft
      HTMLSettings.ImageFolder = 'images'
      HTMLSettings.ImageBaseName = 'img'
      PrintSettings.DateFormat = 'dd/mm/yyyy'
      PrintSettings.Font.Charset = DEFAULT_CHARSET
      PrintSettings.Font.Color = clWindowText
      PrintSettings.Font.Height = -11
      PrintSettings.Font.Name = 'Tahoma'
      PrintSettings.Font.Style = []
      PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
      PrintSettings.FixedFont.Color = clWindowText
      PrintSettings.FixedFont.Height = -11
      PrintSettings.FixedFont.Name = 'Tahoma'
      PrintSettings.FixedFont.Style = []
      PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
      PrintSettings.HeaderFont.Color = clWindowText
      PrintSettings.HeaderFont.Height = -11
      PrintSettings.HeaderFont.Name = 'Tahoma'
      PrintSettings.HeaderFont.Style = []
      PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
      PrintSettings.FooterFont.Color = clWindowText
      PrintSettings.FooterFont.Height = -11
      PrintSettings.FooterFont.Name = 'Tahoma'
      PrintSettings.FooterFont.Style = []
      PrintSettings.PageNumSep = '/'
      SearchFooter.FindNextCaption = 'Find &next'
      SearchFooter.FindPrevCaption = 'Find &previous'
      SearchFooter.Font.Charset = DEFAULT_CHARSET
      SearchFooter.Font.Color = clWindowText
      SearchFooter.Font.Height = -11
      SearchFooter.Font.Name = 'Tahoma'
      SearchFooter.Font.Style = []
      SearchFooter.HighLightCaption = 'Highlight'
      SearchFooter.HintClose = 'Close'
      SearchFooter.HintFindNext = 'Find next occurrence'
      SearchFooter.HintFindPrev = 'Find previous occurrence'
      SearchFooter.HintHighlight = 'Highlight occurrences'
      SearchFooter.MatchCaseCaption = 'Match case'
      SearchFooter.ResultFormat = '(%d of %d)'
      SortSettings.DefaultFormat = ssAutomatic
      SortSettings.Show = True
      SortSettings.IndexShow = True
      SortSettings.NormalCellsOnly = True
      URLUnderlineOnHover = True
      Version = '3.1.6.0'
      Columns = <
        item
          AutoMinSize = 0
          AutoMaxSize = 0
          Alignment = taRightJustify
          Borders = []
          BorderPen.Color = clSilver
          ButtonHeight = 18
          CheckFalse = 'N'
          CheckTrue = 'Y'
          Color = clWindow
          ColumnPopupType = cpFixedCellsRClick
          DropDownCount = 8
          EditLength = 0
          Editor = edNormal
          FilterCaseSensitive = False
          Fixed = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Header = 'Site ID'
          HeaderAlignment = taCenter
          HeaderFont.Charset = DEFAULT_CHARSET
          HeaderFont.Color = clNavy
          HeaderFont.Height = -11
          HeaderFont.Name = 'Tahoma'
          HeaderFont.Style = []
          MinSize = 0
          MaxSize = 0
          Password = False
          PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
          PrintColor = clWhite
          PrintFont.Charset = DEFAULT_CHARSET
          PrintFont.Color = clWindowText
          PrintFont.Height = -11
          PrintFont.Name = 'Tahoma'
          PrintFont.Style = []
          ReadOnly = False
          ShowBands = False
          SortStyle = ssNumeric
          SpinMax = 0
          SpinMin = 0
          SpinStep = 1
          Tag = 0
          Width = 98
        end
        item
          AutoMinSize = 0
          AutoMaxSize = 0
          Alignment = taLeftJustify
          Borders = []
          BorderPen.Color = clSilver
          ButtonHeight = 18
          CheckFalse = 'N'
          CheckTrue = 'Y'
          Color = clWindow
          ColumnPopupType = cpFixedCellsRClick
          DropDownCount = 8
          EditLength = 0
          Editor = edNormal
          FilterCaseSensitive = False
          Fixed = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Header = 'Site Name'
          HeaderAlignment = taCenter
          HeaderFont.Charset = DEFAULT_CHARSET
          HeaderFont.Color = clNavy
          HeaderFont.Height = -11
          HeaderFont.Name = 'Tahoma'
          HeaderFont.Style = []
          MinSize = 0
          MaxSize = 0
          Password = False
          PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
          PrintColor = clWhite
          PrintFont.Charset = DEFAULT_CHARSET
          PrintFont.Color = clWindowText
          PrintFont.Height = -11
          PrintFont.Name = 'Tahoma'
          PrintFont.Style = []
          ReadOnly = False
          ShowBands = False
          SortStyle = ssAutomatic
          SpinMax = 0
          SpinMin = 0
          SpinStep = 1
          Tag = 0
          Width = 98
        end
        item
          AutoMinSize = 0
          AutoMaxSize = 0
          Alignment = taRightJustify
          Borders = []
          BorderPen.Color = clSilver
          ButtonHeight = 18
          CheckFalse = 'N'
          CheckTrue = 'Y'
          Color = clWindow
          ColumnPopupType = cpFixedCellsRClick
          DropDownCount = 8
          EditLength = 0
          Editor = edNormal
          FilterCaseSensitive = False
          Fixed = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Header = 'Latitude'
          HeaderAlignment = taCenter
          HeaderFont.Charset = DEFAULT_CHARSET
          HeaderFont.Color = clNavy
          HeaderFont.Height = -11
          HeaderFont.Name = 'Tahoma'
          HeaderFont.Style = []
          MinSize = 0
          MaxSize = 0
          Password = False
          PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
          PrintColor = clWhite
          PrintFont.Charset = DEFAULT_CHARSET
          PrintFont.Color = clWindowText
          PrintFont.Height = -11
          PrintFont.Name = 'Tahoma'
          PrintFont.Style = []
          ReadOnly = False
          ShowBands = False
          SortStyle = ssNumeric
          SpinMax = 0
          SpinMin = 0
          SpinStep = 1
          Tag = 0
          Width = 98
        end
        item
          AutoMinSize = 0
          AutoMaxSize = 0
          Alignment = taRightJustify
          Borders = []
          BorderPen.Color = clSilver
          ButtonHeight = 18
          CheckFalse = 'N'
          CheckTrue = 'Y'
          Color = clWindow
          ColumnPopupType = cpFixedCellsRClick
          DropDownCount = 8
          EditLength = 0
          Editor = edNormal
          FilterCaseSensitive = False
          Fixed = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Header = 'Longitude'
          HeaderAlignment = taCenter
          HeaderFont.Charset = DEFAULT_CHARSET
          HeaderFont.Color = clNavy
          HeaderFont.Height = -11
          HeaderFont.Name = 'Tahoma'
          HeaderFont.Style = []
          HeaderFont.Quality = fqDraft
          MinSize = 0
          MaxSize = 0
          Password = False
          PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
          PrintColor = clWhite
          PrintFont.Charset = DEFAULT_CHARSET
          PrintFont.Color = clWindowText
          PrintFont.Height = -11
          PrintFont.Name = 'Tahoma'
          PrintFont.Style = []
          ReadOnly = False
          ShowBands = False
          SortStyle = ssNumeric
          SpinMax = 0
          SpinMin = 0
          SpinStep = 1
          Tag = 0
          Width = 98
        end
        item
          AutoMinSize = 0
          AutoMaxSize = 0
          Alignment = taLeftJustify
          Borders = []
          BorderPen.Color = clSilver
          ButtonHeight = 18
          CheckFalse = 'N'
          CheckTrue = 'Y'
          Color = clWindow
          ColumnPopupType = cpFixedCellsRClick
          DropDownCount = 8
          EditLength = 0
          Editor = edNormal
          FilterCaseSensitive = False
          Fixed = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Header = 'Pol Div 1'
          HeaderAlignment = taCenter
          HeaderFont.Charset = DEFAULT_CHARSET
          HeaderFont.Color = clNavy
          HeaderFont.Height = -11
          HeaderFont.Name = 'Tahoma'
          HeaderFont.Style = []
          MinSize = 0
          MaxSize = 0
          Password = False
          PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
          PrintColor = clWhite
          PrintFont.Charset = DEFAULT_CHARSET
          PrintFont.Color = clWindowText
          PrintFont.Height = -11
          PrintFont.Name = 'Tahoma'
          PrintFont.Style = []
          ReadOnly = False
          ShowBands = False
          SortStyle = ssAutomatic
          SpinMax = 0
          SpinMin = 0
          SpinStep = 1
          Tag = 0
          Width = 98
        end
        item
          AutoMinSize = 0
          AutoMaxSize = 0
          Alignment = taLeftJustify
          Borders = []
          BorderPen.Color = clSilver
          ButtonHeight = 18
          CheckFalse = 'N'
          CheckTrue = 'Y'
          Color = clWindow
          ColumnPopupType = cpFixedCellsRClick
          DropDownCount = 8
          EditLength = 0
          Editor = edNormal
          FilterCaseSensitive = False
          Fixed = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          Header = 'Pol Div 2'
          HeaderAlignment = taCenter
          HeaderFont.Charset = DEFAULT_CHARSET
          HeaderFont.Color = clNavy
          HeaderFont.Height = -11
          HeaderFont.Name = 'Tahoma'
          HeaderFont.Style = []
          MinSize = 0
          MaxSize = 0
          Password = False
          PrintBorders = [cbTop, cbLeft, cbRight, cbBottom]
          PrintColor = clWhite
          PrintFont.Charset = DEFAULT_CHARSET
          PrintFont.Color = clWindowText
          PrintFont.Height = -11
          PrintFont.Name = 'Tahoma'
          PrintFont.Style = []
          ReadOnly = False
          ShowBands = False
          SortStyle = ssAutomatic
          SpinMax = 0
          SpinMin = 0
          SpinStep = 1
          Tag = 0
          Width = 97
        end>
      ExplicitLeft = 88
      ExplicitTop = 22
      ExplicitWidth = 400
      ColWidths = (
        98
        98
        98
        98
        98
        97)
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 497
    Width = 784
    Height = 19
    Panels = <>
    SimplePanel = True
  end
  object PleaseWaitGroupBox: TcxGroupBox
    Left = 256
    Top = 168
    PanelStyle.Active = True
    ParentBackground = False
    ParentColor = False
    Style.BorderColor = clNavy
    Style.BorderStyle = ebsSingle
    Style.Color = 15984090
    Style.Edges = [bLeft, bTop, bRight, bBottom]
    Style.LookAndFeel.Kind = lfFlat
    Style.LookAndFeel.NativeStyle = False
    Style.Shadow = True
    Style.TransparentBorder = True
    StyleDisabled.BorderColor = clNavy
    StyleDisabled.Color = clBlack
    StyleDisabled.LookAndFeel.Kind = lfFlat
    StyleDisabled.LookAndFeel.NativeStyle = False
    StyleFocused.LookAndFeel.Kind = lfFlat
    StyleFocused.LookAndFeel.NativeStyle = False
    StyleHot.LookAndFeel.Kind = lfFlat
    StyleHot.LookAndFeel.NativeStyle = False
    TabOrder = 3
    Height = 105
    Width = 300
    object Image1: TImage
      Left = 8
      Top = 8
      Width = 48
      Height = 19
      AutoSize = True
      Picture.Data = {
        07544269746D6170E60A0000424DE60A00000000000036000000280000003000
        0000130000000100180000000000B00A00000000000000000000000000000000
        0000150088150088150088150088150088150088150088150088150088150088
        1500881500881500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        1500881500881500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088150088150088150088FAFAFAFDFDFDFCFCFCFBFAF9
        F7F6F6F9F9F9150088150088150088150088150088150088FAFAFBF2F1F2F3F3
        F3F4F4F4F4F4F4F3F3F3F0F0F0EFEEEEF6F6F7F6F5F515008815008815008815
        0088150088150088150088C5C7C88287867B80809097998D9592A0A6A0A9B1A9
        A9ADA3A2A494ABADA2B6B8B0E0E2E0FBFAFBF3F3F31500881500881500881500
        88F5F5F5F1F1F1F5F4F4E1E3E3CAD1D8D3D8DBE1E0E1EDEDEEF1F1F1EBEBEBDA
        DADABFC0C2D0D2DAD5DDE2E8E7E7EAEAEAE6E6E6DADADACACBCBBEBDBD989B9A
        73787474797FE4E6E5150088150088150088150088150088150088F6F6F6FCFC
        FCFDFDFDFBFBFBFBFBFBFAF9FAF4F4F6F1F1F2E5E7E7C6CAC8ABB0A8A5A79AA4
        A9A5F2F2F2F7F7F7F1F1F1150088150088F2F2F2F5F5F5E5E6E5D3D7DCB5B5B6
        B3B6B6BFBFBFCBCBCBD6D6D6C8C8C8A9A9A7C4CBC3A8A9A9A4A2A1A09D9C9C99
        98929190807F80828180C2C6BADEE1C9808A877E857EB9BBBB15008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        150088F4F3F4F7F6F6FBFBFCE4E5E6A4A5A0A8AEAACACBCBFBFBFBF4F4F4F2F2
        F2F3F2F2F8F7F8888B899B9B97726F6C6C6C6A78787889898A8A8A8B79797963
        676597A9A997ABAF6C80866B828D6B838A4B595F95938AAFC5C092ADB18EA5A5
        889A966A776FB8BABB1500881500881500881500881500881500881500881500
        88150088150088150088150088150088150088150088150088150088F4F4F4FF
        FFFFB3B6B6919B96CFD2D3F8F8F8F2F2F2FFFFFFB2B3B258615DA9B2AFBCC0B6
        B0AEA384867B565550515051888781BCCACBCCE5EEB3D5E5A2C6D7B1D1DC93B3
        BFBDD9E3BFD4D4A6C3C9B6CAC976827E050405586461F6F5F715008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        150088150088150088150088150088150088FFFEFFB0B3B48E9891EFEFF1F8F7
        F79D9D984E595696ADB6CDDEE0BED5DFD0E7EEDEEFF3C8CAC05D6056C9D4D3D0
        E7F2B5D1E1B2D1E0B5D0DFBBD7E0C0DBEAB8D4E2A4C2D1B8C9C6A1B4AC77817A
        0F0F0B6B78791500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088FEFDFD9AA29DADB2B5DFE5D9E4E5E39FBAC5C7D7D9C2D4D8BFD2D8
        DAE7EDD5E7EFBCDCEDCCE1E9B1D2E4A5C5D5A6C4CBB0CDDAAFCDDDA9C9D8A0BD
        C98FADBEA1B9C2BDC9C7B3C1B99DACA56D807E8D9696FDFCFC15008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        150088150088150088150088150088150088150088F9F8F9BDC3BD727A74CBDB
        DCA6BCC7BBCFDCA9B9C29DB8C2BACDD3D0E1E5CEE3EFBCDBEAB8D8F0AED0E6A8
        C8D9A4BFD099B4BF97B7C796B6C28BA8B5798A8A747F83E1E4FB7179867F9494
        203030FFFFFFF3F3F31500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088F8F7F8BCBFBE5D67629FB2B5A8BDC9A0B7C687A1AFA5B9C0C5D5DA
        D2DDE4CBE0EBB9D9EFAACDE2A9CDE4AACCDE9ABDD49BB6C590ADB86F88937994
        9B68797C80847FECEBFF76828B495658AEB3B5FCFBFB15008815008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        150088150088150088150088150088150088150088150088FFFEFF9097947481
        818695998B9CA1B7C8CBBACACCC1D1D7A6C0CBB2CBD7ADC7D49ABDCF92B2C9A1
        BFD099B9CC93AFBD72868B65777D738D967A8B8E979797E3E4EC7D858A5B6463
        FFFFFFF2F2F11500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088FFFFFFA9AEAC72766AABB4AEA4B0AEB3BEBC9FB5BA
        98AEB9A1B5BCA3BAC39CB4C393AFBF819CAEA2C0D5778F9C7F92947281815A6E
        74535F5FBDBAAD9698976C7175929898FCFCFC15008815008815008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        150088150088150088150088150088150088150088150088150088150088FFFE
        FFC6C6C39A9C8799A198A7AEA991A1A1B5BFBC9FAAA9AAB8B7A7B2AF92A6AD6F
        8490708998677A80647171737F80606D6B909693E2E2E2646A6CB2B6AFCECFCF
        F6F6F61500881500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088150088150088FCFBFDCBCBC9868A7A929D9BAAB2AB
        B3BAB3A5B0ABAFB6AFAEB7AF9EA8A47D8A8E56666E59696F4E5B5C596261E2E3
        E2FFFFFFF9F8F9DDDEDDE3E4E6F8F8F815008815008815008815008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        1500881500881500881500881500881500881500881500881500881500881500
        88150088FAFAFBE2E1E0676A64919990A9AEA4B7BAAEAEB3A9A7AEA7969C9680
        8D8E5E6B6F485253555E5CF3F3F3F8F7F7150088150088F5F4F4F4F4F3150088
        1500881500881500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088150088150088150088150088F6F6F7F8F7F8949693
        82877F939A919CA49C848E87828C8A87908D707B78AEB2B1FEFDFEF5F5F51500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        1500881500881500881500881500881500881500881500881500881500881500
        88150088150088150088150088FDFCFDEFEFF1CED2D1C4C7C7C0C3C4BDC0C1C9
        CCCDF3F3F4FCFBFBF3F2F2150088150088150088150088150088150088150088
        1500881500881500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        1500881500881500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        1500881500881500881500881500881500881500881500881500881500881500
        8815008815008815008815008815008815008815008815008815008815008815
        0088150088150088150088150088150088150088150088150088150088150088
        150088150088150088150088150088150088}
      Transparent = True
    end
    object cxLabel7: TcxLabel
      Left = 0
      Top = 43
      AutoSize = False
      Caption = 'Connecting to Neotoma. Please Wait.'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -13
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = [fsBold]
      Style.IsFontAssigned = True
      Properties.Alignment.Horz = taCenter
      Properties.Alignment.Vert = taVCenter
      Transparent = True
      Height = 20
      Width = 300
      AnchorX = 150
      AnchorY = 53
    end
  end
  object TcpClient1: TTcpClient
    Left = 240
    Top = 448
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 200
    OnTimer = Timer1Timer
    Left = 336
    Top = 448
  end
  object cxImageList1: TcxImageList
    FormatVersion = 1
    DesignInfo = 29360416
    ImageInfo = <
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00E9E9E900EBEBEB00FFFF
          FF00FFFFFF00F7F7F700D5D5D500E4E4E400FFFFFF00FFFFFF00C2C3C400BBBE
          C000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00D1D1D100B1B1B100F7F6
          F600FFFFFF00E2E2E2009696960090909000D1D1D100FFFFFF00C8CACC00727D
          8300DFE0E100FFFFFF00FFFFFF00FDFDFD00DADADA00C7C8C800696A6A008B8F
          9300F2F3F400FAFAFA00AAAAAA006A6A6A007E7D7D00D8D8D800FFFFFF00CDD1
          D2008A949700C8CBCC00E6E5E500AAAAAA00696C6D00828789007B8588006571
          7B009BA0A600F9F9F900EFEFEF00858585005257580083858700FFFFFF00FFFF
          FF00C8CBCD00888F92008A8F940085898C00818485003F44460067757A008B93
          960093949300CACACA00EEEEEE00D7D8D800646D710059626500FFFFFF00FFFF
          FF00E3E4E40075828900627487006E7E91007F888E0055606400546268008287
          8900ACAEB000CFCECE00D8D8D800EFEEEE00CCCECF005E696D00FFFFFF00FFFF
          FF00D7DADA0064737B005B718C004C64830050616B0051626800536166007B82
          85008E929900ECECEC00F3F3F300F9F9F900F9F9F90077828700FFFFFF00FEFE
          FE00A1AAAE0053646B00515B6500485866004D606800465C6800576C7D00B4B7
          B700DCDCDC00F8F8F900FFFFFF00FFFFFF00FFFFFF00A7AFB200FFFFFF00FFFE
          FE008A969B00475E6600545D610033444C00445960004B5F6D00586F8A006873
          790060697300D0D3D700FFFFFF00FFFFFF00FFFFFF00A9B1B400FFFFFF00FFFF
          FF00949B9F003A5059003B4D5400182E3700384C5400535D6200535F6B00727F
          85006F7A82008D949900DDDDDE00FEFEFE00EFF0F0008E9A9E00FFFFFF00FFFF
          FF00D5D5D50057666B002F48510018343F00253D460048565C00555F63007A87
          8C0087919500717B8000989D9F00F8F8F800A4ACAF00B9C0C300FFFFFF00FFFF
          FF00F2F1F0006C797E00324F5A00203F4A00233D47003C505900596B72007482
          8800818C9200818C91008B9498009EA3A6009CA5A800FBFCFC00FFFFFF00FFFF
          FF00DDDDDC005D6B7000324D58002B46510029454F00394F5800435860006071
          780075848A00768489007F888B00B3B8BA00F7F8F800FFFFFF00FFFFFF00FFFF
          FF00FBFBFB00D8DBDC00B8BFC2007C898F00364D5600344B5400395159004258
          610062717700848D9100DADBDB00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00F4F4F4008D979A0043565E0028414B003145
          4E0079808300EBEBEB00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FDFDFC00CACECF00859297007880
          8400D3D3D300FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00}
        MaskColor = clWhite
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000001200000033000000330000003300000033000000330000
          0033000000330000001200000000000000000000000000000000000000000000
          0000000000121116457C2C3CC0FF2B3BBEFF2B3ABEFF2B3ABEFF2B3ABEFF2B3B
          BEFF2C3CC0FF1116457C00000012000000000000000000000000000000000000
          0012101543792F3EC3FF5F71F9FF697DFFFF697CFFFF697CFFFF697CFFFF697D
          FFFF5F71F9FF2F3EC3FF10154379000000120000000000000000000000121015
          43792F3EC2FF586BF6FF5F74FFFF5D72FEFF5E72FDFF5E73FDFF5E72FDFF5D72
          FEFF5F74FFFF586BF6FF2F3EC2FF1015437900000012000000001116457C303F
          C2FF5568F3FF586CFCFF4E64F9FF4D63F8FF5468F9FF576BF9FF5468F9FF4D63
          F8FF4E64F9FF586CFCFF5568F3FF303FC2FF1116457C000000002D3DC0FF5367
          F2FF556BFAFF4960F7FFFFFFFFFFFFFFFFFF3E56F6FF475EF6FF3E56F6FFFFFF
          FFFFFFFFFFFF4960F7FF556BFAFF5166F2FF2D3DC0FF000000002B3BBFFF6276
          FCFF4D64F6FF4259F4FFFFFFFFFFFFFFFFFFFFFFFFFF2C46F3FFFFFFFFFFFFFF
          FFFFFFFFFFFF4259F4FF4E64F6FF5F75FCFF2C3BBFFF000000002A3ABFFF7386
          FAFF495FF3FF435AF3FF6E80F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFF6E80F6FF435AF3FF495FF3FF6E81FAFF2B3ABFFF000000002939BFFF8696
          FBFF425AF1FF4259F1FF354EF0FF5B70F2FFFFFFFFFFFFFFFFFFFFFFFFFF5B70
          F2FF354EF0FF4259F1FF435BF1FF7D90F9FF2A39BFFF000000002737BFFF9AA8
          FBFF3A55EFFF3953EEFF2844EDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFF2844EDFF3953EEFF3B55EFFF8E9DFAFF2838BFFF000000002637BFFF9FAB
          F1FF314CEDFF2B47EBFFFFFFFFFFFFFFFFFFFFFFFFFF5369EFFFFFFFFFFFFFFF
          FFFFFFFFFFFF2C47EBFF314CEDFF9FABF1FF2737BFFF000000002838C1FF9FAB
          F1FF8091F4FF213EE8FFFFFFFFFFFFFFFFFF5D72EEFF2340E8FF5D72EEFFFFFF
          FFFFFFFFFFFF213EE8FF8091F4FF9FABF1FF2838C1FF000000001016455B2E3E
          C3FF97A5EFFF778AF2FF5B71EEFF6074EEFF2643E6FF2C48E7FF2643E6FF6074
          EEFF5B71EEFF778AF2FF97A5EFFF2E3EC3FF1016455B00000000000000000F15
          43582E3EC2FF95A2EEFF7688F0FF1E3BE4FF2340E5FF2541E5FF2340E5FF1E3B
          E4FF7688F0FF95A2EEFF2E3EC2FF0F1543580000000000000000000000000000
          00000F1543582F3DC3FF94A0EFFFADB9F8FFADB8F7FFADB9F7FFADB8F7FFADB9
          F8FF94A0EFFF2F3DC3FF0F154358000000000000000000000000000000000000
          0000000000001015455B303FC4FF4555CEFF4454CDFF4354CDFF4454CDFF4555
          CEFF303FC4FF1015455B00000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000028160B30000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000007946228F361F0F400000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000001B100820BD6C34DF0D07041000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000AF622FCF6B3B1D8000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000077411F8FCA6D36EF0D070310000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000005B301670DB753EFF4D271160000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000331A0C40DD783EFF8C4620AFD05F29FFD05F
          29FFD05F29FFD05F29FFD05F29FFD05F29FFD05F29FFA2481CCF000000000000
          0000000000000000000000000000401F0D50DE783EFF9A4B22BFD05F29FFDA76
          45FFD8713CFFD9713AFFDD6F36FFDC6932FFA3471CCF0C050210000000000000
          0000000000000000000000000000642F1480E47B41FFA65024CFD05F29FFD672
          40FFD36B35FFD76F39FFDF7947FFB04E21DF0C05021000000000000000000000
          0000000000000000000000000000A34B20CFE57A40FF97441EBFD05F29FFD671
          40FFD77442FFD56D38FFDD7A47FFD16534FF2510073000000000000000000000
          000000000000000000003E1C0C50D56935FFE37941FF883E1CAFD05F29FFDB82
          56FFDF8A62FFDD8053FFD56C37FFDE7B4AFFC46032EF57261070000000000000
          00000000000031160940C0592AEFE37841FFD86C38FF49200E60D05F29FFDD8D
          67FFBC552BEFD7794FFFDC7F50FFD46C36FFDE7A49FFD76E3DFFB35126DF9944
          1FBFA64B22CFD46633FFE0743EFFE0743EFFBB5326EF0C050210D05F29FFA34C
          29CF0C0502107031168FD47247FFDE8357FFD7713EFFD76F3AFFDC7440FFDE72
          3DFFDD713BFFDB703AFFDE723CFFCF602FFF3C190A5000000000A64C21CC0C05
          021000000000000000003E1A0B50B4572FDFDA7A4FFFDD7E50FFDB7645FFDA72
          3FFFDC703CFFD86735FFBC5226EF3C190B5000000000000000000F0703120000
          0000000000000000000000000000000000004B1E0C608A3C1DAF984623BF9744
          21BF95401DBF54230E700C050210000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000403F3F423939
          393900000000000000000000000013131313B5B5B5B6EBEBEBFFD4D4D4E40000
          000020202020E2E2E2FFD0D0D0FF828282952A2A2A2A00000000C4C5C8FF9CA0
          A3F00606060600000000000000000F0F0F0FC7C7C7C8B1B1B1FF959594F65F5F
          5F650C0C0C0CB8B8B8FB656565FF797979FFCDCDCCF23D3D3D3D888B8DC77884
          89FF878989A9393939392121212154545476A4A6A6EF9C9D9FFF424647FF8C93
          9BFF5757595D36363644818181ED454545FF6C6B6BFFDBDBDBF70C0C0C0C888C
          8EC48A9397FFB0B1B2F49A9A9ADC7F8080FF4B4F51FF555D60FF657277FF4A55
          5FFFA4A5A7FD50505052A6A5A5C1686A6BFF22282CFF939697FF000000002323
          2323A1A6A7F9666F74FF697179FF6E7477FF5D6061FF283135FF546369FF8E91
          92FFA19F9EFFC3C3C3FFEBE9E9F8D5D3D5FF485256FF43484BFF000000001A1A
          1A1AAFB2B2F9415261FF405674FF50627AFF565F64FF374449FF3C474BFF7074
          79FFA5A7AAFFECECEBFFD3CED1FFCFD4D0FFB1B0B3FF374348FF000000001313
          13148E9697F93E4F5DFF3C5472FF30445CFF334249FF31424AFF4C585CFF8D91
          94FF6C6E71AE9999999A6AA389F10BA161FF7DA794FF505461FF000000007E7E
          7F8E5F7077FD354348FF384147FF30404AFF32454CFF263F53FF586879FFB3B3
          B3FF7B777BAE32614B9A00A465F100DC99FF13B377FF335950FF000000007E7E
          7E8E4F626AFD2E4148FF2E363BFF16262CFF304247FF36495CFF45586EFF474D
          56FF455E61FF29B177FF27DAA6FF00DAA3FF29D5A3FF0E9258FF000000000F0E
          0E165C666BFF21343DFF18262DFF081820FF2B393FFF3C4246FF424D55FF6772
          79FF56646AFF436E5DFF13A26CFF02DAA3FF028857FF769A8CF1000000001111
          1111757575C22E4047FF172C35FF091D26FF19292FFF313D42FF4B585CFF6775
          7AFF6F787DFF605E66FF1F9164FF04D4A2FF42AD83FF56484F5B000000001414
          14148E8E8ECC3B4D54FF132C37FF0C222DFF192B33FF283A43FF45565DFF5969
          6FFF6B767BFF60696FFF239469FF17D7ADFF20895CCE13131313000000001616
          1616ADADADDC8B9295FF2F444DFF152A34FF182D36FF22353DFF2B3D45FF4A59
          61FF58666DFF596469FF2E996FFF28DDB8FF006134B100000000000000000000
          00001818181C3D3E3E54757879A3848F94FF1B2F37FF172A33FF1C313AFF283B
          43FF4C585EFB979A99EC4BAE84FB29D5B5FF006639B600000000000000000000
          00000000000000000000000000008586859171787BE63E4F57FF091D26FF333F
          44FF8E8E8FE2111111112C8C64D25CEBD9FF03693EB900000000000000000000
          000000000000000000000000000000000000202020206566677EA4ABADFFB0B2
          B3FF5E5D5D6400000000076239AB26AF78FF02532F9300000000}
      end>
  end
  object ipsJSONS1: TipsJSONS
    SSLCertStore = 'MY'
    OnSSLServerAuthentication = ipsJSONS1SSLServerAuthentication
    Left = 200
    Top = 448
  end
end
