object DendrogramForm: TDendrogramForm
  Left = 548
  Top = 120
  HelpContext = 130
  BorderIcons = [biSystemMenu, biMinimize, biMaximize, biHelp]
  BorderStyle = bsDialog
  Caption = 'Cluster Analysis'
  ClientHeight = 408
  ClientWidth = 593
  Color = clBtnFace
  ParentFont = True
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000000000
    0000000080000080000000808000800000008000800080800000C0C0C0008080
    80000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC444
    4444444444444444444444444444CF555555555555555555555555555557CF77
    77777777777777777777777777F7CF7FFFFFFFFFFFFFFFFFFFFFFFFFFFF7CF7F
    FFF0FF0FF0FF0FF0FF0FF0FF0FF7CF7FFFF0000000FF0000FF0000000FF7CF7F
    FFF222FFFFFF5FFFFF1FFFFFFFF7CF7FFFF22222FFFF5FFFFF11FFFFFFF70F00
    FFF22222FFFF5FFFFF111FFFFFF7CF7FFFF2222FFFFF55FFFF1FFFFFFFF7CF7F
    FFF222FFFFFF5FFFFF111FFFFFF70F00FFF2FFFFFFFF5FFFFF1111FFFFF7CF7F
    FFF2FFFFFFFF555FFF111FFFFFF7CF7FFFF2FFFFFFFF555FFF11111FFFF70F00
    FFF2FFFFFFFF5FFFFF111111FFF7CF7FFFF2FFFFFFFF5FFFFF111111FFF7CF7F
    FFF2FFFFFFFF55FFFF11111FFFF70F00FFF2FFFFFFFF5FFFFF111111FFF7CF7F
    FFF2FFFFFFFF5FFFFF11111FFFF7CF7FFFF2FFFFFFFF5FFFFF111FFFFFF70F00
    FFFFFFFFFFFFFFFFFFFFFFFFFFF7CF7FFFF0FFFFFFFFF0FFFFF0FFFFFFF7CF7F
    FFFF0FFFFFFFFF0FFFFF0FFFFFF7CFFFFFFFF0FFFFFFFFF0FFFFF0FFFFF7CFFF
    FFFFFFFFFFFFFFFFFFFFFF0FFFF7C7777777777777777777777777777777FFFF
    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000}
  OldCreateOrder = False
  Position = poMainFormCenter
  ShowHint = True
  OnActivate = FormActivate
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnHelp = FormHelp
  PixelsPerInch = 96
  TextHeight = 13
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 56
    Width = 217
    Height = 97
    HelpContext = 131
    Caption = 'Dendrogram Scale'
    Items.Strings = (
      'Increase in sum of squares'
      'Total sum of squares'
      'Within-cluster sum of squares'
      'Mean within-cluster sum of squares')
    TabOrder = 0
    OnClick = RadioGroup1Click
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 265
    Width = 217
    Height = 88
    HelpContext = 133
    Caption = 'Title'
    TabOrder = 1
    object Edit1: TEdit
      Left = 8
      Top = 24
      Width = 161
      Height = 21
      TabOrder = 0
    end
    object LabeledEdit8: TLabeledEdit
      Left = 144
      Top = 56
      Width = 65
      Height = 21
      EditLabel.Width = 44
      EditLabel.Height = 13
      EditLabel.Caption = 'Y Offset:'
      LabelPosition = lpLeft
      TabOrder = 1
    end
    object cxButton1: TcxButton
      Left = 8
      Top = 56
      Width = 73
      Height = 21
      Caption = 'Font'
      LookAndFeel.Kind = lfOffice11
      OptionsImage.Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C30E0000EA0E00000000000000000000C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0800000800000800000800000800000C0C0C0C0C0C0C0C0C08000
        00800000800000800000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C080000080
        0000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0800000800000C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0800000800000C0C0C0C0C0C0C0C0C0C0C0
        C0800000800000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0800000800000800000800000800000800000800000C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0800000800000C0C0C0C0C0
        C0800000800000C0C0C0C0C0C0000000C0C0C0C0C0C0C0C0C0000000C0C0C0C0
        C0C0C0C0C0C0C0C0800000800000C0C0C0800000800000C0C0C0C0C0C0000000
        808080C0C0C0808080000000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C08000008000
        00800000800000C0C0C0C0C0C0808080000000000000000000808080C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0800000800000800000C0C0C0C0C0C0C0C0C0
        000000C0C0C0000000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0800000800000C0C0C0C0C0C0C0C0C0000000C0C0C0000000C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        808080000000808080C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0000000C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0}
      TabOrder = 2
      OnClick = cxButton1Click
    end
    object cxButton4: TcxButton
      Left = 168
      Top = 24
      Width = 41
      Height = 21
      Caption = 'Default'
      LookAndFeel.Kind = lfOffice11
      TabOrder = 3
      OnClick = cxButton4Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 164
    Width = 217
    Height = 88
    HelpContext = 132
    Caption = 'Axis Label'
    TabOrder = 2
    object Edit2: TEdit
      Left = 8
      Top = 24
      Width = 161
      Height = 21
      TabOrder = 0
      OnExit = Edit2Exit
    end
    object cxButton2: TcxButton
      Left = 8
      Top = 56
      Width = 73
      Height = 21
      Caption = 'Font'
      LookAndFeel.Kind = lfOffice11
      OptionsImage.Glyph.Data = {
        36030000424D3603000000000000360000002800000010000000100000000100
        18000000000000030000C30E0000EA0E00000000000000000000C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0800000800000800000800000800000C0C0C0C0C0C0C0C0C08000
        00800000800000800000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C080000080
        0000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0800000800000C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0800000800000C0C0C0C0C0C0C0C0C0C0C0
        C0800000800000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0800000800000800000800000800000800000800000C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0800000800000C0C0C0C0C0
        C0800000800000C0C0C0C0C0C0000000C0C0C0C0C0C0C0C0C0000000C0C0C0C0
        C0C0C0C0C0C0C0C0800000800000C0C0C0800000800000C0C0C0C0C0C0000000
        808080C0C0C0808080000000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C08000008000
        00800000800000C0C0C0C0C0C0808080000000000000000000808080C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0800000800000800000C0C0C0C0C0C0C0C0C0
        000000C0C0C0000000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0800000800000C0C0C0C0C0C0C0C0C0000000C0C0C0000000C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        808080000000808080C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0000000C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
        C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0}
      TabOrder = 1
      OnClick = cxButton2Click
    end
    object cxButton5: TcxButton
      Left = 168
      Top = 24
      Width = 41
      Height = 21
      Caption = 'Default'
      LookAndFeel.Kind = lfOffice11
      TabOrder = 2
      OnClick = cxButton5Click
    end
  end
  object GroupBox3: TGroupBox
    Left = 376
    Top = 24
    Width = 209
    Height = 329
    Caption = 'Tic Marks'
    TabOrder = 3
    object GroupBox8: TGroupBox
      Left = 8
      Top = 24
      Width = 193
      Height = 85
      HelpContext = 135
      Caption = 'Step Size'
      TabOrder = 0
      object LabeledEdit1: TLabeledEdit
        Left = 120
        Top = 32
        Width = 65
        Height = 21
        EditLabel.Width = 78
        EditLabel.Height = 13
        EditLabel.Caption = 'Major Tic Marks:'
        EditLabel.Color = clBtnFace
        EditLabel.ParentColor = False
        LabelPosition = lpLeft
        TabOrder = 0
      end
      object LabeledEdit2: TLabeledEdit
        Left = 120
        Top = 56
        Width = 65
        Height = 21
        EditLabel.Width = 77
        EditLabel.Height = 13
        EditLabel.Caption = 'Minor Tic Marks:'
        LabelPosition = lpLeft
        TabOrder = 1
      end
      object CheckBox1: TCheckBox
        Left = 120
        Top = 12
        Width = 65
        Height = 17
        Caption = 'Automatic'
        TabOrder = 2
        OnClick = CheckBox1Click
      end
    end
    object GroupBox4: TGroupBox
      Left = 88
      Top = 224
      Width = 113
      Height = 97
      HelpContext = 137
      Caption = 'Lengths'
      TabOrder = 2
      object LabeledEdit5: TLabeledEdit
        Left = 40
        Top = 20
        Width = 65
        Height = 21
        EditLabel.Width = 30
        EditLabel.Height = 13
        EditLabel.Caption = 'Minor:'
        LabelPosition = lpLeft
        TabOrder = 0
      end
      object LabeledEdit6: TLabeledEdit
        Left = 40
        Top = 44
        Width = 65
        Height = 21
        EditLabel.Width = 31
        EditLabel.Height = 13
        EditLabel.Caption = 'Major:'
        LabelPosition = lpLeft
        TabOrder = 1
      end
      object LabeledEdit7: TLabeledEdit
        Left = 40
        Top = 68
        Width = 65
        Height = 21
        EditLabel.Width = 22
        EditLabel.Height = 13
        EditLabel.Caption = 'Top:'
        LabelPosition = lpLeft
        TabOrder = 2
      end
    end
    object GroupBox5: TGroupBox
      Left = 13
      Top = 117
      Width = 193
      Height = 101
      HelpContext = 136
      Caption = 'Labels'
      TabOrder = 1
      object LabeledEdit3: TLabeledEdit
        Left = 120
        Top = 20
        Width = 65
        Height = 21
        EditLabel.Width = 110
        EditLabel.Height = 13
        EditLabel.Caption = 'Distance from tic mark:'
        LabelPosition = lpLeft
        TabOrder = 0
      end
      object LabeledEdit9: TLabeledEdit
        Left = 120
        Top = 44
        Width = 65
        Height = 21
        EditLabel.Width = 72
        EditLabel.Height = 13
        EditLabel.Caption = 'Decimal points:'
        LabelPosition = lpLeft
        TabOrder = 1
      end
      object cxButton6: TcxButton
        Left = 120
        Top = 72
        Width = 65
        Height = 21
        Caption = 'Font'
        LookAndFeel.Kind = lfOffice11
        OptionsImage.Glyph.Data = {
          36030000424D3603000000000000360000002800000010000000100000000100
          18000000000000030000C30E0000EA0E00000000000000000000C0C0C0C0C0C0
          C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
          C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
          C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
          C0C0C0C0C0C0800000800000800000800000800000C0C0C0C0C0C0C0C0C08000
          00800000800000800000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C080000080
          0000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0800000800000C0C0C0C0C0C0C0C0C0
          C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0800000800000C0C0C0C0C0C0C0C0C0C0C0
          C0800000800000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
          C0C0800000800000800000800000800000800000800000C0C0C0C0C0C0C0C0C0
          C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0800000800000C0C0C0C0C0
          C0800000800000C0C0C0C0C0C0000000C0C0C0C0C0C0C0C0C0000000C0C0C0C0
          C0C0C0C0C0C0C0C0800000800000C0C0C0800000800000C0C0C0C0C0C0000000
          808080C0C0C0808080000000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C08000008000
          00800000800000C0C0C0C0C0C0808080000000000000000000808080C0C0C0C0
          C0C0C0C0C0C0C0C0C0C0C0C0C0C0800000800000800000C0C0C0C0C0C0C0C0C0
          000000C0C0C0000000C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
          C0800000800000C0C0C0C0C0C0C0C0C0000000C0C0C0000000C0C0C0C0C0C0C0
          C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
          808080000000808080C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
          C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0000000C0C0C0C0C0C0C0C0C0C0
          C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
          C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
          C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0
          C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0}
        TabOrder = 2
        OnClick = cxButton6Click
      end
    end
  end
  object GroupBox6: TGroupBox
    Left = 232
    Top = 240
    Width = 137
    Height = 113
    Caption = 'Axes'
    TabOrder = 4
    object Label1: TLabel
      Left = 8
      Top = 24
      Width = 29
      Height = 13
      Caption = 'Color:'
    end
    object Label2: TLabel
      Left = 8
      Top = 64
      Width = 54
      Height = 13
      Caption = 'Line Width:'
    end
    object ColorBox1: TColorBox
      Left = 8
      Top = 40
      Width = 121
      Height = 22
      HelpContext = 7
      Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
      TabOrder = 0
    end
    object LineWidthComboBox2: TComboBox
      Left = 8
      Top = 80
      Width = 121
      Height = 21
      HelpContext = 6
      TabOrder = 1
    end
  end
  object GroupBox7: TGroupBox
    Left = 232
    Top = 56
    Width = 137
    Height = 153
    Caption = 'Dendrogram'
    TabOrder = 5
    object Label3: TLabel
      Left = 8
      Top = 64
      Width = 29
      Height = 13
      Caption = 'Color:'
    end
    object Label4: TLabel
      Left = 8
      Top = 104
      Width = 54
      Height = 13
      Caption = 'Line Width:'
    end
    object LabeledEdit4: TLabeledEdit
      Left = 8
      Top = 40
      Width = 121
      Height = 21
      HelpContext = 134
      EditLabel.Width = 32
      EditLabel.Height = 13
      EditLabel.Caption = 'Width:'
      TabOrder = 0
    end
    object ColorBox2: TColorBox
      Left = 8
      Top = 80
      Width = 121
      Height = 22
      HelpContext = 7
      Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
      TabOrder = 1
    end
    object LineWidthComboBox1: TComboBox
      Left = 8
      Top = 120
      Width = 121
      Height = 21
      HelpContext = 6
      TabOrder = 2
    end
  end
  object CheckBox2: TCheckBox
    Left = 264
    Top = 24
    Width = 97
    Height = 17
    HelpContext = 138
    Caption = 'Plot Dendrogram'
    TabOrder = 6
  end
  object cxButton3: TcxButton
    Left = 8
    Top = 16
    Width = 105
    Height = 25
    Caption = 'Open .dgx File'
    LookAndFeel.Kind = lfOffice11
    TabOrder = 7
    OnClick = cxButton3Click
  end
  object cxButton7: TcxButton
    Left = 8
    Top = 368
    Width = 75
    Height = 25
    Caption = 'Ok'
    LookAndFeel.Kind = lfOffice11
    ModalResult = 1
    TabOrder = 8
    OnClick = cxButton7Click
  end
  object cxButton8: TcxButton
    Left = 96
    Top = 368
    Width = 75
    Height = 25
    Caption = 'Cancel'
    LookAndFeel.Kind = lfOffice11
    ModalResult = 2
    TabOrder = 9
  end
  object cxButton9: TcxButton
    Left = 184
    Top = 368
    Width = 75
    Height = 25
    Caption = 'Help'
    LookAndFeel.Kind = lfOffice11
    TabOrder = 10
    OnClick = cxButton9Click
  end
  object OpenDialog1: TOpenDialog
    Filter = 'CONISS xml file (*.dgx)|*.dgx'
    Left = 552
    Top = 368
  end
  object ipwXMLp1: TipwXMLp
    BuildDOM = False
    OnCharacters = ipwXMLp1Characters
    OnEndElement = ipwXMLp1EndElement
    OnStartElement = ipwXMLp1StartElement
    Left = 520
    Top = 368
  end
end
