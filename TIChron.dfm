object ChronForm: TChronForm
  Left = 428
  Top = 163
  Caption = 'Chronology'
  ClientHeight = 668
  ClientWidth = 540
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poDesktopCenter
  OnActivate = FormActivate
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 436
    Width = 540
    Height = 232
    Align = alBottom
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 4
      Width = 59
      Height = 13
      Caption = 'Chronology:'
    end
    object RadioGroup1: TRadioGroup
      Left = 16
      Top = 48
      Width = 129
      Height = 133
      Caption = 'Age Model:'
      Enabled = False
      Items.Strings = (
        'Linear interpolation'
        'Polynomial'
        'Cubic spline'
        'Cubic B-spline'
        'LOWESS')
      TabOrder = 0
      OnClick = RadioGroup1Click
    end
    object ComboBox1: TComboBox
      Left = 16
      Top = 20
      Width = 75
      Height = 21
      Style = csDropDownList
      TabOrder = 1
      OnChange = ComboBox1Change
    end
    object RadioGroup2: TRadioGroup
      Left = 156
      Top = 118
      Width = 97
      Height = 63
      Caption = 'Plot'
      Enabled = False
      Items.Strings = (
        'Function'
        'Sample ages')
      TabOrder = 2
      OnClick = RadioGroup2Click
    end
    object LabeledEdit1: TLabeledEdit
      Left = 104
      Top = 20
      Width = 208
      Height = 21
      Color = clBtnFace
      EditLabel.Width = 31
      EditLabel.Height = 13
      EditLabel.Caption = 'Name:'
      ReadOnly = True
      TabOrder = 3
    end
    object LabeledEdit2: TLabeledEdit
      Left = 324
      Top = 20
      Width = 208
      Height = 21
      Color = clBtnFace
      EditLabel.Width = 54
      EditLabel.Height = 13
      EditLabel.Caption = 'Age Model:'
      ReadOnly = True
      TabOrder = 4
    end
    object RadioGroup3: TRadioGroup
      Left = 264
      Top = 118
      Width = 113
      Height = 63
      Caption = 'Symbols'
      Items.Strings = (
        'Points'
        'Age Limits')
      TabOrder = 5
      OnClick = RadioGroup3Click
    end
    object GroupBox1: TGroupBox
      Left = 156
      Top = 48
      Width = 97
      Height = 68
      Caption = 'Extrapolate'
      TabOrder = 6
      object CheckBox2: TCheckBox
        Left = 8
        Top = 18
        Width = 65
        Height = 17
        Caption = 'Younger'
        Enabled = False
        TabOrder = 0
        OnClick = CheckBox2Click
      end
      object CheckBox3: TCheckBox
        Left = 8
        Top = 42
        Width = 65
        Height = 17
        Caption = 'Older'
        Enabled = False
        TabOrder = 1
        OnClick = CheckBox3Click
      end
    end
    object GroupBox2: TGroupBox
      Left = 264
      Top = 48
      Width = 112
      Height = 68
      Caption = 'Depth Limits'
      TabOrder = 8
      object LabeledEdit3: TLabeledEdit
        Left = 32
        Top = 16
        Width = 68
        Height = 21
        Color = clBtnFace
        EditLabel.Width = 20
        EditLabel.Height = 13
        EditLabel.Caption = 'Min:'
        Enabled = False
        LabelPosition = lpLeft
        TabOrder = 0
        OnChange = LabeledEdit3Change
        OnExit = LabeledEdit3Exit
      end
      object LabeledEdit4: TLabeledEdit
        Left = 32
        Top = 40
        Width = 68
        Height = 21
        Color = clBtnFace
        EditLabel.Width = 24
        EditLabel.Height = 13
        EditLabel.Caption = 'Max:'
        Enabled = False
        LabelPosition = lpLeft
        TabOrder = 1
        OnChange = LabeledEdit4Change
        OnExit = LabeledEdit4Exit
      end
    end
    object GroupBox3: TGroupBox
      Left = 386
      Top = 48
      Width = 145
      Height = 85
      Caption = 'Save Options'
      TabOrder = 7
      object CheckBox1: TCheckBox
        Left = 8
        Top = 26
        Width = 57
        Height = 17
        Caption = 'Round'
        Checked = True
        State = cbChecked
        TabOrder = 0
      end
      object cxSpinEdit1: TcxSpinEdit
        Left = 72
        Top = 24
        Properties.MaxValue = 15.000000000000000000
        Properties.ValueType = vtInt
        Style.BorderStyle = ebs3D
        TabOrder = 1
        Width = 49
      end
      object CheckBox4: TCheckBox
        Left = 8
        Top = 56
        Width = 129
        Height = 17
        Caption = 'Null ages outside limits'
        Checked = True
        State = cbChecked
        TabOrder = 2
      end
    end
    object cxButton1: TcxButton
      Left = 386
      Top = 156
      Width = 145
      Height = 25
      Caption = 'Save to Spreadsheet'
      LookAndFeel.Kind = lfOffice11
      TabOrder = 9
      OnClick = cxButton1Click
    end
    object cxButton2: TcxButton
      Left = 368
      Top = 192
      Width = 75
      Height = 25
      Caption = 'Cancel'
      LookAndFeel.Kind = lfOffice11
      ModalResult = 2
      TabOrder = 10
    end
    object cxButton3: TcxButton
      Left = 16
      Top = 192
      Width = 75
      Height = 25
      Caption = 'New'
      LookAndFeel.Kind = lfOffice11
      TabOrder = 11
      OnClick = cxButton3Click
    end
    object cxButton4: TcxButton
      Left = 192
      Top = 192
      Width = 75
      Height = 25
      Caption = 'Zoom Out'
      LookAndFeel.Kind = lfOffice11
      TabOrder = 12
      OnClick = cxButton4Click
    end
    object cxButton5: TcxButton
      Left = 280
      Top = 192
      Width = 75
      Height = 25
      Caption = 'Results'
      LookAndFeel.Kind = lfOffice11
      TabOrder = 13
      OnClick = cxButton5Click
    end
    object cxButton6: TcxButton
      Left = 104
      Top = 192
      Width = 75
      Height = 25
      Caption = 'Go'
      LookAndFeel.Kind = lfOffice11
      TabOrder = 14
      OnClick = cxButton6Click
    end
    object cxButton7: TcxButton
      Left = 456
      Top = 192
      Width = 75
      Height = 25
      Caption = 'Done'
      LookAndFeel.Kind = lfOffice11
      ModalResult = 1
      TabOrder = 15
    end
  end
  object Chart1: TChart
    Left = 0
    Top = 0
    Width = 540
    Height = 436
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Legend.Visible = False
    Title.Text.Strings = (
      'Age-Depth')
    OnScroll = Chart1Scroll
    OnZoom = Chart1Zoom
    BottomAxis.LabelStyle = talValue
    BottomAxis.Title.Caption = 'Depth'
    Chart3DPercent = 10
    LeftAxis.Title.Caption = 'Age'
    View3D = False
    Align = alClient
    TabOrder = 1
    OnMouseDown = Chart1MouseDown
    OnMouseUp = Chart1MouseUp
    ColorPaletteIndex = 13
    object Series1: TPointSeries
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.Callout.Length = 8
      Marks.BackColor = clRed
      Marks.Color = clRed
      Marks.Visible = False
      SeriesColor = clRed
      ClickableLine = False
      Pointer.Brush.Color = clRed
      Pointer.Brush.Gradient.EndColor = clRed
      Pointer.Gradient.EndColor = clRed
      Pointer.HorizSize = 2
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.VertSize = 2
      Pointer.Visible = True
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series2: TLineSeries
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.Visible = False
      SeriesColor = clRed
      LinePen.Color = clRed
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series3: TPointSeries
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.Visible = False
      SeriesColor = clGreen
      ClickableLine = False
      Pointer.Brush.Color = clRed
      Pointer.Brush.Gradient.EndColor = clGreen
      Pointer.Gradient.EndColor = clGreen
      Pointer.HorizSize = 2
      Pointer.InflateMargins = False
      Pointer.Style = psRectangle
      Pointer.VertSize = 1
      Pointer.Visible = True
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series4: TPointSeries
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.Visible = False
      SeriesColor = clYellow
      ClickableLine = False
      Pointer.Brush.Color = clRed
      Pointer.HorizSize = 2
      Pointer.InflateMargins = False
      Pointer.Style = psRectangle
      Pointer.VertSize = 1
      Pointer.Visible = True
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
end
