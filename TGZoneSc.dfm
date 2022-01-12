object ZoneScreenForm: TZoneScreenForm
  Left = 352
  Top = 180
  HelpContext = 92
  BorderIcons = [biSystemMenu, biHelp]
  BorderStyle = bsDialog
  Caption = 'Zone Screen Options'
  ClientHeight = 401
  ClientWidth = 321
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poOwnerFormCenter
  ShowHint = True
  OnActivate = FormActivate
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnHelp = FormHelp
  PixelsPerInch = 96
  TextHeight = 13
  object PaintBox1: TPaintBox
    Left = 16
    Top = 144
    Width = 289
    Height = 25
    Hint = 'Example'
    OnPaint = PaintBox1Paint
  end
  object Label5: TLabel
    Left = 16
    Top = 280
    Width = 56
    Height = 13
    Caption = 'Zone Color:'
  end
  object Panel1: TPanel
    Left = 16
    Top = 16
    Width = 289
    Height = 113
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object RadioGroup1: TRadioGroup
      Left = 12
      Top = 8
      Width = 73
      Height = 89
      Hint = 'Zone style'
      HelpContext = 93
      Caption = 'Style'
      Items.Strings = (
        'Pattern'
        'Solid'
        'Dashed')
      TabOrder = 0
      OnClick = RadioGroup1Click
    end
    object Button5: TButton
      Left = 96
      Top = 16
      Width = 57
      Height = 25
      Hint = 'Click to select pattern for Pattern style'
      HelpContext = 10
      Caption = 'Pattern'
      Enabled = False
      TabOrder = 1
      OnClick = Button5Click
    end
    object LabeledEdit1: TLabeledEdit
      Left = 96
      Top = 74
      Width = 81
      Height = 21
      Hint = 'Dash width for Dashed style'
      HelpContext = 94
      Color = clBtnFace
      EditLabel.Width = 59
      EditLabel.Height = 13
      EditLabel.Caption = 'Dash Width:'
      TabOrder = 2
      OnExit = LabeledEdit1Exit
    end
    object LabeledEdit2: TLabeledEdit
      Left = 192
      Top = 74
      Width = 81
      Height = 21
      Hint = 'Space width for Dashed style'
      HelpContext = 94
      Color = clBtnFace
      EditLabel.Width = 64
      EditLabel.Height = 13
      EditLabel.Caption = 'Space Width:'
      TabOrder = 3
      OnExit = LabeledEdit2Exit
    end
  end
  object Button1: TButton
    Left = 16
    Top = 368
    Width = 65
    Height = 25
    Caption = '&Ok'
    ModalResult = 1
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 88
    Top = 368
    Width = 65
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 2
  end
  object Button3: TButton
    Left = 160
    Top = 368
    Width = 65
    Height = 25
    Caption = '&Help'
    TabOrder = 3
    OnClick = Button3Click
  end
  object CheckBox2: TCheckBox
    Left = 16
    Top = 336
    Width = 153
    Height = 17
    Hint = 'Check this box to apply options to all screen zones'
    HelpContext = 97
    Caption = 'Apply to all screen zones'
    TabOrder = 4
  end
  object GroupBox1: TGroupBox
    Left = 172
    Top = 178
    Width = 133
    Height = 143
    HelpContext = 92
    Caption = 'Zone Borders'
    TabOrder = 5
    object Label2: TLabel
      Left = 8
      Top = 48
      Width = 54
      Height = 13
      Caption = 'Line Width:'
    end
    object Label6: TLabel
      Left = 8
      Top = 94
      Width = 64
      Height = 13
      Caption = 'Border Color:'
      FocusControl = ColorBox2
    end
    object CheckBox1: TCheckBox
      Left = 8
      Top = 24
      Width = 97
      Height = 17
      Hint = 'Check this box to draw borders around zone screen'
      HelpContext = 96
      Caption = 'Draw Borders'
      TabOrder = 0
      OnClick = CheckBox1Click
    end
    object LineWidthComboBox1: TComboBox
      Left = 8
      Top = 64
      Width = 97
      Height = 21
      Hint = 'Border line width'
      HelpContext = 6
      TabOrder = 1
    end
    object ColorBox2: TColorBox
      Left = 8
      Top = 110
      Width = 121
      Height = 22
      Hint = 'Border color'
      HelpContext = 7
      Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
      TabOrder = 2
      OnChange = ColorBox2Change
    end
  end
  object ColorBox1: TColorBox
    Left = 16
    Top = 296
    Width = 121
    Height = 22
    Hint = 'Zone color'
    HelpContext = 7
    Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
    TabOrder = 6
    OnChange = ColorBox1Change
  end
  object GroupBox2: TGroupBox
    Left = 16
    Top = 184
    Width = 149
    Height = 89
    Hint = 'Zone width'
    HelpContext = 95
    Caption = 'Zone Width'
    TabOrder = 7
    object LabeledEdit3: TLabeledEdit
      Left = 8
      Top = 56
      Width = 61
      Height = 21
      Hint = 'Zone width'
      HelpContext = 95
      EditLabel.Width = 32
      EditLabel.Height = 13
      EditLabel.Caption = 'Width:'
      TabOrder = 0
    end
    object RadioGroup3: TRadioGroup
      Left = 76
      Top = 14
      Width = 65
      Height = 65
      Hint = 'Units for zone width'
      HelpContext = 95
      Caption = 'Units'
      Items.Strings = (
        'Virtual'
        'Depth')
      TabOrder = 1
    end
  end
  object ColorDialog1: TColorDialog
    Left = 248
    Top = 352
  end
end
