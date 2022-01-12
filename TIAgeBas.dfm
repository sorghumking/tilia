object ChronControlForm: TChronControlForm
  Left = 386
  Top = 518
  BorderStyle = bsDialog
  Caption = 'Chronology Control'
  ClientHeight = 441
  ClientWidth = 482
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel4: TPanel
    Left = 0
    Top = 0
    Width = 482
    Height = 48
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object LabeledEdit1: TLabeledEdit
      Left = 8
      Top = 24
      Width = 465
      Height = 21
      EditLabel.Width = 97
      EditLabel.Height = 13
      EditLabel.Caption = 'Chronology Control:'
      TabOrder = 0
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 48
    Width = 482
    Height = 126
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object GroupBox1: TGroupBox
      Left = 8
      Top = 0
      Width = 225
      Height = 121
      Caption = 'Radiocarbon Ages'
      Ctl3D = True
      ParentCtl3D = False
      TabOrder = 0
      object LabeledEdit2: TLabeledEdit
        Left = 104
        Top = 24
        Width = 105
        Height = 21
        EditLabel.Width = 76
        EditLabel.Height = 13
        EditLabel.Caption = 'Older Age Limit:'
        LabelPosition = lpLeft
        TabOrder = 0
      end
      object LabeledEdit3: TLabeledEdit
        Left = 104
        Top = 56
        Width = 105
        Height = 21
        EditLabel.Width = 90
        EditLabel.Height = 13
        EditLabel.Caption = 'Younger Age Limit:'
        LabelPosition = lpLeft
        TabOrder = 1
      end
      object LabeledEdit4: TLabeledEdit
        Left = 104
        Top = 88
        Width = 105
        Height = 21
        EditLabel.Width = 23
        EditLabel.Height = 13
        EditLabel.Caption = 'Age:'
        LabelPosition = lpLeft
        TabOrder = 2
      end
    end
    object GroupBox2: TGroupBox
      Left = 248
      Top = -1
      Width = 225
      Height = 121
      Caption = 'Calendar or Calibrated Ages'
      TabOrder = 1
      object LabeledEdit5: TLabeledEdit
        Left = 104
        Top = 24
        Width = 105
        Height = 21
        EditLabel.Width = 76
        EditLabel.Height = 13
        EditLabel.Caption = 'Older Age Limit:'
        LabelPosition = lpLeft
        TabOrder = 0
      end
      object LabeledEdit6: TLabeledEdit
        Left = 104
        Top = 56
        Width = 105
        Height = 21
        EditLabel.Width = 90
        EditLabel.Height = 13
        EditLabel.Caption = 'Younger Age Limit:'
        LabelPosition = lpLeft
        TabOrder = 1
      end
      object LabeledEdit7: TLabeledEdit
        Left = 104
        Top = 88
        Width = 105
        Height = 21
        EditLabel.Width = 23
        EditLabel.Height = 13
        EditLabel.Caption = 'Age:'
        LabelPosition = lpLeft
        TabOrder = 2
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 174
    Width = 482
    Height = 200
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 2
    object Label1: TLabel
      Left = 8
      Top = 0
      Width = 32
      Height = 13
      Caption = 'Notes:'
    end
    object Label2: TLabel
      Left = 8
      Top = 80
      Width = 60
      Height = 13
      Caption = 'Publications:'
    end
    object Label3: TLabel
      Left = 248
      Top = 0
      Width = 45
      Height = 13
      Caption = 'Age Unit:'
      Visible = False
    end
    object Memo1: TMemo
      Left = 8
      Top = 16
      Width = 465
      Height = 50
      TabOrder = 0
    end
    object ComboBox1: TComboBox
      Left = 248
      Top = 16
      Width = 225
      Height = 21
      Style = csDropDownList
      TabOrder = 3
      Visible = False
    end
    object FlowPanel2: TFlowPanel
      Left = 8
      Top = 96
      Width = 465
      Height = 100
      BevelInner = bvRaised
      BevelOuter = bvLowered
      Ctl3D = True
      ParentCtl3D = False
      TabOrder = 1
      object AdvColumnGrid1: TAdvColumnGrid
        Left = 2
        Top = 2
        Width = 463
        Height = 74
        Cursor = crDefault
        BevelInner = bvNone
        BevelOuter = bvNone
        BorderStyle = bsNone
        ColCount = 2
        Ctl3D = True
        DefaultRowHeight = 18
        DrawingStyle = gdsClassic
        FixedCols = 0
        RowCount = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentCtl3D = False
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 0
        ActiveRowShow = True
        ActiveRowColor = 15387318
        HoverRowCells = [hcNormal, hcSelected]
        OnGetEditorProp = AdvColumnGrid1GetEditorProp
        ActiveCellFont.Charset = DEFAULT_CHARSET
        ActiveCellFont.Color = clWindowText
        ActiveCellFont.Height = -11
        ActiveCellFont.Name = 'Tahoma'
        ActiveCellFont.Style = [fsBold]
        ColumnHeaders.Strings = (
          'ID'
          'Publication')
        ColumnSize.Stretch = True
        ColumnSize.StretchColumn = 1
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
        FilterDropDownClear = '(All)'
        FilterEdit.TypeNames.Strings = (
          'Starts with'
          'Ends with'
          'Contains'
          'Not contains'
          'Equal'
          'Not equal'
          'Clear')
        FixedColWidth = 48
        FixedRowHeight = 18
        FixedFont.Charset = DEFAULT_CHARSET
        FixedFont.Color = clWindowText
        FixedFont.Height = -11
        FixedFont.Name = 'Tahoma'
        FixedFont.Style = [fsBold]
        FloatFormat = '%.2f'
        HoverButtons.Buttons = <>
        HoverButtons.Position = hbLeftFromColumnLeft
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
        Version = '3.1.6.0'
        WordWrap = False
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
            Header = 'ID'
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
            ReadOnly = True
            ShowBands = False
            SortStyle = ssAutomatic
            SpinMax = 0
            SpinMin = 0
            SpinStep = 1
            Tag = 0
            Width = 48
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
            EditLink = FormControlEditLink1
            Editor = edCustom
            FilterCaseSensitive = False
            Fixed = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            Header = 'Publication'
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
            Width = 415
          end>
        ColWidths = (
          48
          415)
        object cxMemo1: TcxMemo
          Left = 102
          Top = 19
          Properties.ReadOnly = True
          Properties.ScrollBars = ssVertical
          Style.BorderColor = clSilver
          Style.BorderStyle = ebsSingle
          Style.LookAndFeel.Kind = lfFlat
          StyleDisabled.LookAndFeel.Kind = lfFlat
          StyleFocused.LookAndFeel.Kind = lfFlat
          StyleHot.LookAndFeel.Kind = lfFlat
          TabOrder = 2
          Height = 30
          Width = 63
        end
        object AdvControlDropDown1: TAdvControlDropDown
          Left = 159
          Top = 21
          Width = 90
          Height = 21
          EmptyTextFocused = False
          EmptyTextStyle = []
          Visible = False
          DropDownColor = 15984090
          DropDownColorTo = 15785680
          DropDownBorderColor = clNone
          DropDownHeight = 100
          LabelMargin = 0
          LabelFont.Charset = DEFAULT_CHARSET
          LabelFont.Color = clWindowText
          LabelFont.Height = -11
          LabelFont.Name = 'Tahoma'
          LabelFont.Style = []
          Version = '1.4.5.7'
          ButtonAppearance.BorderColorHot = 10079963
          ButtonAppearance.BorderColorDown = 4370174
          ButtonAppearance.Color = 16773091
          ButtonAppearance.ColorTo = 16768452
          ButtonAppearance.ColorDisabledTo = 11974326
          ButtonAppearance.ColorDown = 11196927
          ButtonAppearance.ColorDownTo = 7257087
          ButtonAppearance.ColorHot = 15465983
          ButtonAppearance.ColorHotTo = 11332863
          ButtonAppearance.Font.Charset = DEFAULT_CHARSET
          ButtonAppearance.Font.Color = clWindowText
          ButtonAppearance.Font.Height = -11
          ButtonAppearance.Font.Name = 'Tahoma'
          ButtonAppearance.Font.Style = []
          DropDownHeader.Color = 16773091
          DropDownHeader.ColorTo = 16765615
          DropDownHeader.Caption = 'Publication'
          DropDownHeader.Font.Charset = DEFAULT_CHARSET
          DropDownHeader.Font.Color = 7485192
          DropDownHeader.Font.Height = -11
          DropDownHeader.Font.Name = 'Tahoma'
          DropDownHeader.Font.Style = [fsBold]
          DropDownHeader.Visible = True
          DropDownHeader.BorderColor = 16765615
          DropDownHeader.Buttons = <>
          DropDownFooter.Color = 16773091
          DropDownFooter.ColorTo = 16765615
          DropDownFooter.Font.Charset = DEFAULT_CHARSET
          DropDownFooter.Font.Color = 7485192
          DropDownFooter.Font.Height = -11
          DropDownFooter.Font.Name = 'Tahoma'
          DropDownFooter.Font.Style = []
          DropDownFooter.Visible = True
          DropDownFooter.BorderColor = 16765615
          DropDownFooter.Buttons = <
            item
              Caption = 'Ok'
              ModalResult = 1
            end>
          TabOrder = 3
          Control = cxMemo1
          SelectionColorStyle = 1
          TMSStyle = 4
        end
      end
      object cxButton4: TcxButton
        Left = 2
        Top = 76
        Width = 47
        Height = 21
        Hint = 'Remove publication'
        LookAndFeel.Kind = lfFlat
        OptionsImage.Glyph.Data = {
          F6070000424DF60700000000000036000000280000001F000000100000000100
          200000000000C007000000000000000000000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFE1E1E1FFCECECEFFCCCCCCFFCCCCCCFFCCCCCCFFCECE
          CEFFE1E1E1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFC0C0C0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1F1
          F1FFCCCCCCFF7079C6FF3140C0FF2B3BBEFF2B3ABEFF2B3BBEFF3140C0FF7079
          C6FFCCCCCCFFF1F1F1FFFFFFFFFFFFFFFFFFA4A0A0FFC0C0C0FFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FFA4A0A0FFFFFFFFFFFFFFFFFFFFFF
          FFFF806060FFA4A0A0FFC0C0C0FFFFFFFFFFFFFFFFFFF1F1F1FFA1A5C9FF2B3B
          BEFF4A5BE2FF6175FCFF697DFFFF697CFFFF697DFFFF6175FCFF4A5BE2FF2B3B
          BEFFA1A5C9FFF1F1F1FFFFFFFFFFC0C0C0FF806060FFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFC0C0C0FF806060FF80A0A0FFFFFFFFFFFFFFFFFFC0C0
          C0FF806060FFA4A0A0FFC0C0C0FFFFFFFFFFA1A5C9FF2F3FC2FF596DF6FF6276
          FFFF6074FEFF5F73FEFF5F73FDFF5F73FEFF6074FEFF6276FFFF596DF6FF2F3F
          C2FFA1A5C9FFFFFFFFFFFFFFFFFFC0C0C0FF8060A0FFC0C0C0FFC0C0C0FFC0C0
          C0FF806060FFA4A0A0FF806060FF8060A0FFA4A0A0FFFFFFFFFFC0C0C0FFA4A0
          A0FF404040FFA4A0A0FFE1E1E1FF2C3CBFFF5669F4FF5D71FCFF5B6FFAFF5A6E
          F9FF5A6EF9FF5A6EF9FF5A6EF9FF5A6EF9FF5B6FFAFF5D71FCFF5669F4FF2C3C
          BFFFE1E1E1FFFFFFFFFFFFFFFFFFC0C0C0FF80A0A0FFA4A0A0FFA4A0A0FFA4A0
          A0FF404040FF80A0A0FFA4A0A0FFA4A0A0FFC0C0C0FFFFFFFFFFC0C0C0FF8060
          A0FF806060FF717AC7FF4256DEFF576DFBFF5369F8FF5268F7FF5267F7FF5267
          F7FF5267F7FF5267F7FF5267F7FF5268F7FF5369F8FF576DFBFF4256DEFF717A
          C7FFFFFFFFFFFFFFFFFFC0C0C0FF80A0A0FF406060FF8060A0FF806060FF8060
          60FF404060FFA4A0A0FFA4A0A0FFC0C0C0FFC0C0C0FFFFFFFFFFC0C0C0FF8060
          60FF3242C0FF4E64F4FF4C63F7FF425AF4FF3E56F4FF3D55F4FF3D55F4FF3D55
          F4FF3D55F4FF3D55F4FF3E56F4FF425AF4FF4C63F7FF4E64F4FF3242C0FFFFFF
          FFFFFFFFFFFFFFFFFFFF806060FF8060A0FF406060FF8060A0FF406060FF8060
          60FF806060FFA4A0A0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8060A0FF2C3C
          BFFF5369F8FF3E56F3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFF3E56F3FF5369F8FF2C3CBFFFFFFFFFFFFFFF
          FFFFA4A0A0FF806060FF404060FF806060FF404060FF406060FF406060FFC0C0
          C0FFC0C0C0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF80C0C0FF2B3BBFFF6378
          F7FF334DF0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFF334DF0FF6378F7FF2B3BBFFFFFFFFFFFFFFFFFFFA4A0
          A0FF406060FF806060FF404040FF806060FF406060FF80A0A0FF806060FF8060
          A0FFC0C0C0FFFFFFFFFFFFFFFFFFFFFFFFFFA4A0A0FF2A39BFFF8696F8FF2F4B
          EEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFF2F4BEEFF8696F8FF2A39BFFFFFFFFFFFFFFFFFFFA4A0A0FF4060
          60FF404040FF404040FF404040FF806060FF404060FF8060A0FF806060FFA4A0
          A0FFC0C0C0FFFFFFFFFFC0C0C0FFA4A0A0FF2F3EC1FFA1ACF4FF3852EDFF2D48
          ECFF2B46EBFF2A46EBFF2A46EBFF2A46EBFF2A46EBFF2A46EBFF2B46EBFF2D48
          ECFF3852EDFFA1ACF4FF2F3EC1FFFFFFFFFFFFFFFFFFFFFFFFFF806060FF4060
          60FF004040FF406060FF406060FF806060FF806060FFA4A0A0FF806060FFA4A0
          A0FFFFFFFFFFC0C0C0FFC0C0C0FF838CDBFF6F7CDDFF8494F5FF2E4AE9FF334D
          E9FF354FEAFF3650EAFF3650EAFF3650EAFF354FEAFF334DE9FF2E4AE9FF8494
          F5FF6F7CDDFF838CDBFFFFFFFFFFFFFFFFFFC0C0C0FF8060A0FF404040FF4040
          60FF004040FF406060FF406060FF80A0A0FF806060FFA4A0A0FF80A0A0FFA4A0
          A0FFA4A0A0FFFFFFFFFFFFFFFFFF2737BFFF9AA7F0FF7F90F3FF324CE9FF2D49
          E7FF304CE8FF314CE8FF304CE8FF2D49E7FF324CE9FF7F90F3FF9AA7F0FF2737
          BFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF806060FF406060FF404060FF4060
          60FF404060FF806060FF806060FFA4A0A0FF8060A0FFA4A0A0FF80C0C0FFFFFF
          FFFFFFFFFFFFFFFFFFFFC5CAEEFF2F3FC3FF97A3EFFF9EACF7FF6075EDFF3E57
          E9FF2441E5FF3E57E9FF6075EDFF9EACF7FF97A3EFFF2F3FC3FFC5CAEEFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FFA4A0A0FF80A0A0FF404040FF4060
          60FF404040FF406060FF806060FFA4A0A0FFC0C0C0FFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFC5C9EEFF2737BFFF6A77DCFF9EA9F2FFAFBAF8FFAFBB
          F8FFAFBAF8FF9EA9F2FF6A77DCFF2737BFFFC5C9EEFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA4A0A0FF406060FF4060
          60FF404040FFA4A0A0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFF838CDBFF2F3EC2FF2737BFFF2737BFFF2737
          BFFF2F3EC2FF838CDBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FF80A0A0FFA4A0
          A0FFC0C0C0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        OnClick = cxButton4Click
      end
      object cxButton5: TcxButton
        Left = 49
        Top = 76
        Width = 47
        Height = 21
        Hint = 'Add publication'
        LookAndFeel.Kind = lfFlat
        OptionsImage.Glyph.Data = {
          F6070000424DF60700000000000036000000280000001F000000100000000100
          200000000000C007000000000000000000000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFF5F5F5FFDADADAFFCCCCCCFFCCCCCCFFCCCCCCFFCCCC
          CCFFDADADAFFF5F5F5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFC0C0C0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFDDDDDDFFA3C0B3FF369D6EFF008C4BFF008B4AFF008B4AFF008C4BFF369D
          6EFFA3C0B3FFE1E1E1FFFFFFFFFFFFFFFFFFA4A0A0FFC0C0C0FFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FFA4A0A0FFFFFFFFFFFFFFFFFFFFFF
          FFFF806060FFA4A0A0FFC0C0C0FFFFFFFFFFFFFFFFFFFFFFFFFFE1E1E1FF44A2
          77FF009050FF01A169FF00AA76FF00AB77FF00AB77FF00AA76FF01A169FF0090
          50FF55A882FFE1E1E1FFFFFFFFFFC0C0C0FF806060FFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFC0C0C0FF806060FF80A0A0FFFFFFFFFFFFFFFFFFC0C0
          C0FF806060FFA4A0A0FFC0C0C0FFFFFFFFFFF5F5F5FF55A882FF009152FF02AC
          77FF00C38CFF00D699FF18DEA8FF18DEA8FF00D699FF00C38CFF01AB76FF0092
          53FF55A882FFF5F5F5FFFFFFFFFFC0C0C0FF8060A0FFC0C0C0FFC0C0C0FFC0C0
          C0FF806060FFA4A0A0FF806060FF8060A0FFA4A0A0FFFFFFFFFFC0C0C0FFA4A0
          A0FF404040FFA4A0A0FFFFFFFFFFAECABEFF009051FF0FB483FF02D299FF00D6
          9BFF00D193FFFFFFFFFFFFFFFFFF00D193FF00D69BFF00D198FF01AB76FF0090
          50FFAECBBEFFFFFFFFFFFFFFFFFFC0C0C0FF80A0A0FFA4A0A0FFA4A0A0FFA4A0
          A0FF404040FF80A0A0FFA4A0A0FFA4A0A0FFC0C0C0FFFFFFFFFFC0C0C0FF8060
          A0FF806060FFFFFFFFFF369D6CFF16AB78FF11C997FF00D49AFF00D297FF00CD
          8EFFFFFFFFFFFFFFFFFF00CD8EFF00D297FF00D59BFF00C18CFF01A169FF369E
          6EFFFFFFFFFFFFFFFFFFC0C0C0FF80A0A0FF406060FF8060A0FF806060FF8060
          60FF404060FFA4A0A0FFA4A0A0FFC0C0C0FFC0C0C0FFFFFFFFFFC0C0C0FF8060
          60FFFFFFFFFF008A48FF38C49CFF00D198FF00CD92FF00CB8EFF00C787FFFFFF
          FFFFFFFFFFFF00C787FF00CB8EFF00CE93FF00D09AFF00AB76FF008C4BFFFFFF
          FFFFFFFFFFFFFFFFFFFF806060FF8060A0FF406060FF8060A0FF406060FF8060
          60FF806060FFA4A0A0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8060A0FFFFFF
          FFFF008946FF51D2AFFF12D4A3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFF00CF97FF00AD78FF008B4AFFFFFFFFFFFFFF
          FFFFA4A0A0FF806060FF404060FF806060FF404060FF406060FF406060FFC0C0
          C0FFC0C0C0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF80C0C0FFFFFFFFFF0088
          45FF66DDBEFF10D0A2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFF00CD97FF00AD78FF008B4AFFFFFFFFFFFFFFFFFFA4A0
          A0FF406060FF806060FF404040FF806060FF406060FF80A0A0FF806060FF8060
          A0FFC0C0C0FFFFFFFFFFFFFFFFFFFFFFFFFFA4A0A0FFFFFFFFFF008846FF76E0
          C5FF00CA98FF00C590FF00C48EFF00C187FFFFFFFFFFFFFFFFFF00C187FF00C4
          8EFF00C793FF00CB99FF00AB76FF008C4BFFFFFFFFFFFFFFFFFFA4A0A0FF4060
          60FF404040FF404040FF404040FF806060FF404060FF8060A0FF806060FFA4A0
          A0FFC0C0C0FFFFFFFFFFC0C0C0FFA4A0A0FFFFFFFFFF41A675FF59C9A4FF49DE
          BCFF00C794FF00C794FF00C38EFFFFFFFFFFFFFFFFFF00C38EFF00C896FF00CB
          9AFF06C190FF00A168FF40A878FFFFFFFFFFFFFFFFFFFFFFFFFF806060FF4060
          60FF004040FF406060FF406060FF806060FF806060FFA4A0A0FF806060FFA4A0
          A0FFFFFFFFFFC0C0C0FFC0C0C0FFFFFFFFFFCCE8DBFF0A9458FFADF8E9FF18D0
          A7FF00C494FF00C290FFFFFFFFFFFFFFFFFF00C391FF00C799FF05C89BFF18B7
          87FF009050FFCCE8DBFFFFFFFFFFFFFFFFFFC0C0C0FF8060A0FF404040FF4040
          60FF004040FF406060FF406060FF80A0A0FF806060FFA4A0A0FF80A0A0FFA4A0
          A0FFA4A0A0FFFFFFFFFFFFFFFFFFFFFFFFFF55B185FF199C63FFBCFFF7FF5DE4
          C9FF00C397FF00BF90FF00C091FF00C498FF22CAA2FF31C297FF039355FF6ABC
          96FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF806060FF406060FF404060FF4060
          60FF404060FF806060FF806060FFA4A0A0FF8060A0FFA4A0A0FF80C0C0FFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6ABB94FF0E9659FF74D5B6FF9FF3
          E0FF92EFDAFF79E5CAFF5DD6B5FF2EB586FF039152FF55B288FFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FFA4A0A0FF80A0A0FF404040FF4060
          60FF404040FF406060FF806060FFA4A0A0FFC0C0C0FFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCCE8DBFF44A877FF008744FF0087
          43FF008744FF008946FF44AA7AFFCCE8DBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA4A0A0FF406060FF4060
          60FF404040FFA4A0A0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FF80A0A0FFA4A0
          A0FFC0C0C0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = cxButton5Click
      end
    end
    object cxGroupBox1: TcxGroupBox
      Left = 152
      Top = 6
      PanelStyle.Active = True
      PanelStyle.OfficeBackgroundKind = pobkGradient
      ParentBackground = False
      ParentColor = False
      Style.BorderStyle = ebsOffice11
      Style.Color = clGradientActiveCaption
      Style.Edges = [bLeft, bTop, bRight, bBottom]
      Style.LookAndFeel.Kind = lfFlat
      Style.LookAndFeel.NativeStyle = False
      Style.Shadow = True
      Style.TextColor = clNavy
      Style.TransparentBorder = True
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.NativeStyle = False
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.NativeStyle = False
      StyleHot.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.NativeStyle = False
      TabOrder = 2
      Height = 74
      Width = 177
      object cxLabel1: TcxLabel
        Left = 2
        Top = 2
        Align = alClient
        Caption = 'Please Wait'
        ParentFont = False
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clNavy
        Style.Font.Height = -16
        Style.Font.Name = 'Tahoma'
        Style.Font.Style = []
        Style.IsFontAssigned = True
        Properties.Alignment.Horz = taCenter
        Properties.Alignment.Vert = taVCenter
        AnchorX = 87
        AnchorY = 36
      end
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 374
    Width = 482
    Height = 48
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 3
    object FlowPanel1: TFlowPanel
      Left = 128
      Top = 12
      Width = 225
      Height = 25
      AutoSize = True
      AutoWrap = False
      BevelOuter = bvNone
      TabOrder = 0
      object cxButton1: TcxButton
        Left = 0
        Top = 0
        Width = 75
        Height = 25
        Caption = 'Ok'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 1
        OptionsImage.ImageIndex = 0
        OptionsImage.Images = cxImageList1
        TabOrder = 0
      end
      object cxButton2: TcxButton
        Left = 75
        Top = 0
        Width = 75
        Height = 25
        Caption = 'Cancel'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 2
        OptionsImage.ImageIndex = 1
        OptionsImage.Images = cxImageList1
        TabOrder = 1
        OnClick = cxButton2Click
      end
      object cxButton3: TcxButton
        Left = 150
        Top = 0
        Width = 75
        Height = 25
        Caption = 'Upload'
        LookAndFeel.Kind = lfOffice11
        OptionsImage.ImageIndex = 2
        OptionsImage.Images = cxImageList1
        TabOrder = 2
        OnClick = cxButton3Click
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 422
    Width = 482
    Height = 19
    Panels = <>
  end
  object ipsHTTPS1: TipsHTTPS
    SSLCertStore = 'MY'
    TransferredDataLimit = 65536
    Left = 40
    Top = 384
  end
  object TcpClient1: TTcpClient
    Left = 72
    Top = 384
  end
  object FormControlEditLink1: TFormControlEditLink
    Tag = 0
    WantKeyLeftRight = False
    WantKeyUpDown = False
    WantKeyHomeEnd = False
    WantKeyPriorNext = False
    Control = AdvControlDropDown1
    OnSetEditorValue = FormControlEditLink1SetEditorValue
    OnGetEditorValue = FormControlEditLink1GetEditorValue
    Left = 264
    Top = 296
  end
  object cxImageList1: TcxImageList
    FormatVersion = 1
    DesignInfo = 25166224
    ImageInfo = <
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000000000000000000000A000000250000003300000033000000330000
          0033000000250000000A00000000000000000000000000000000000000000000
          00000000000000000022001D105C006738C9008C4BFF008B4AFF008B4AFF008C
          4BFF006738C9001D105C0000001E000000000000000000000000000000000000
          00000000001E005E33BB009050FF01A169FF01AB76FF01AC79FF01AC79FF01AB
          76FF01A169FF009050FF00532DAA0000001E0000000000000000000000000000
          000A00532DAA009152FF02AC77FF00C38CFF00D79BFF00DA9CFF00DA9CFF00D7
          9CFF01C38CFF01AB76FF009253FF00532DAA0000000A0000000000000000001C
          1051009051FF0FB483FF00D298FF00D598FF00D192FF00CF90FF00D091FF00D3
          96FF00D69BFF00D198FF01AB76FF009050FF001D105100000000000000000067
          36C916AB78FF10C996FF00D397FF00CD8CFFFFFFFFFFFFFFFFFFFFFFFFFF00CC
          8CFF00D195FF00D59BFF01C18CFF01A169FF006838C90000000000000000008A
          48FF39C49DFF00D198FF00CB8CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFF00CA8CFF00CF96FF00D29BFF01AB76FF008C4BFF00000000000000000089
          46FF52D2B0FF00CC92FFFFFFFFFFFFFFFFFFFFFFFFFF00C484FFFFFFFFFFFFFF
          FFFFFFFFFFFF00C88DFF00D09AFF00AD79FF008B4AFF00000000000000000088
          45FF68DDBEFF00C991FFFFFFFFFFFFFFFFFF00C68CFF00C891FF00C58BFFFFFF
          FFFFFFFFFFFFFFFFFFFF00CC96FF00AD78FF008B4AFF00000000000000000088
          46FF76E0C6FF00CB98FF00C590FF00C691FF00C895FF00C997FF00C894FF00C3
          8CFFFFFFFFFFFFFFFFFF00C792FF00AB75FF008C4BFF00000000000000000065
          34BE59C9A4FF49DEBCFF00C794FF00C897FF00C998FF00C999FF00C998FF00C7
          94FF00C38EFFFFFFFFFF00BD8AFF00A067FF006838BF0000000000000000001C
          0F330A9458FFADF8E9FF18D0A7FF00C495FF00C697FF00C698FF00C798FF00C7
          98FF00C697FF00C596FF12B585FF008F50FF001C0F3300000000000000000000
          0000005C30AA199C63FFBCFFF7FF5EE4C9FF00C59AFF00C396FF00C497FF00C5
          9AFF22CAA2FF2FC196FF029355FF00522C950000000000000000000000000000
          00000000000000512A950E9659FF74D5B6FFA0F4E1FF94EFDCFF7CE6CCFF5ED6
          B5FF2EB587FF039152FF005D33AA000000000000000000000000000000000000
          00000000000000000000001C0F33006433BB008744FF008743FF008744FF0089
          46FF006636BB001C0F3300000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
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
          2000000000000004000000000000000000000000000000000000414141473636
          363602020202000000000000000010101010AFAFAFB3F3F4F4FFCBCBCBD20505
          050526262626DBDBDBFCCFCFCFFF8787879A2626262600000000C5C8CAFF9599
          9CDF1F1F1F1F000000000000000013131313C7C7C7C9B6B5B5FF929291F15C5B
          5B6717171717ABABABE66C6C6CFF797A7AFFC1C1C1E744444444818487BB7C86
          8CFF818586AD3C3C3C3C27272728525151799FA1A2E7989A9BFF4A4D4EFF838A
          91F45B5B5E624342424A797979E6454545FF6E6E6FFFD6D6D6E9161717177F83
          85BB939C9FFFA4A5A5DE959594D67E7F7FFF515557FF555D60FF5F6B70FF535E
          67FF97989AEE5454545C9D9D9DB96F7172FF20282BFF97989AFF000000003232
          32329B9FA1EB6F777DFF6C747DFF6F7579FF595B5DFF293236FF536269FF898E
          8EFFA3A1A1FFBEBEBEF7EBE8E9F2D6D2D5FF4F565CFF404648FF000000002525
          2525A6A8A8E24A5A69FF3D5472FF52627BFF545E62FF354246FF3C484CFF7075
          79FFA6A7AAFFE8E9E8FFC3C8C5FFC7CEC7FF949E9DFF354146FF000000002626
          262A858D8EE4435561FF3A516EFF31455DFF33444AFF304148FF4F595FFF8D91
          94FF78787BB09797969B419E76E812AE6DFF53A180FF535A65FF000000007677
          778365757CF9344248FF394248FF2F4049FF30454BFF263E53FF586879FFAAAB
          ACFF89898CAB3C35323E00713DAB00E89DFF4AB789FF6F6F79FF000000007374
          758252666EF92C3E45FF2C3539FF19282EFF304147FF36495DFF45576DFF434E
          55FF727784FF979292B81B8E5FC900DB9BFF38A377FF7F7F87FF000000001D1D
          1D2C566064E8263842FF18262EFF081920FF29383EFF3C4247FF434F55FF606D
          73FF5A616BFF7B8081FC34AD7EFD05D79EFF17865DFF97959DED000000001414
          14147E7E7EB63E4F56FF122832FF0A1E26FF192830FF323D42FF4C585CFF6976
          7BFF70767EFF535D60FF24986DFF0DD4A0FF44AE83FF4E474A5B000000001C1C
          1C1C89898AC0374B54FF0E2934FF0C222CFF192B32FF283B43FF44565CFF5B6B
          70FF6E747EFF5E6269FF2F966EFF21DBADFF218458C908080808000000001F1F
          1F1F8C8D8FC55B6B72F8344A53FF172D36FF162B34FF22353EFF2B3E46FF4B59
          61FF56676BFF306652FF1A9C6FFF1ED8B0FF007547CA00261160000000000000
          000022222225404143576D7174A5828E92FF20343CFF152831FF1A2F38FF2D3A
          44FF3B5751F5269E6BF320C9A4FF00BD9CFF29CBA6FF1A8D58E9000000000000
          000000000000000000000E0E0E0E77777887707779DD3E4F56FF0C2029FF3A45
          4BFF7B7C7DCD18422B613FB390EB4FD9C3FF3DAA88E60D291B48000000000000
          0000000000000000000000000000000000001D1D1D1D6A6D6E899EA6A8FDADB0
          B1FF625F6066000000000C3D246732A36FE6082D185100000000}
      end>
  end
  object ipsJSONS1: TipsJSONS
    SSLCertStore = 'MY'
    OnSSLServerAuthentication = ipsJSONS1SSLServerAuthentication
    Left = 8
    Top = 384
  end
end
