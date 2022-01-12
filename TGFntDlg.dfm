object FontDialogBox: TFontDialogBox
  Left = 451
  Top = 316
  Hint = 'Font dialog box'
  BorderIcons = [biSystemMenu, biMinimize, biMaximize, biHelp]
  BorderStyle = bsDialog
  Caption = 'Font Dialog Box'
  ClientHeight = 170
  ClientWidth = 275
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  ShowHint = True
  OnHelp = FormHelp
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 16
    Top = 16
    Width = 56
    Height = 13
    Caption = 'Font Name:'
  end
  object Label3: TLabel
    Left = 192
    Top = 64
    Width = 23
    Height = 13
    Caption = 'Size:'
  end
  object Label4: TLabel
    Left = 16
    Top = 64
    Width = 29
    Height = 13
    Caption = 'Color:'
  end
  object ComboBox1: TComboBox
    Left = 192
    Top = 80
    Width = 72
    Height = 21
    Hint = 'Font size'
    TabOrder = 0
    Items.Strings = (
      '8'
      '9'
      '10'
      '11'
      '12'
      '14'
      '16'
      '18'
      '20'
      '22'
      '24'
      '26'
      '28'
      '36'
      '48'
      '72')
  end
  object ColorBox1: TColorBox
    Left = 16
    Top = 80
    Width = 160
    Height = 22
    Hint = 'Color'
    HelpContext = 7
    Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
    TabOrder = 1
  end
  object Button1: TButton
    Left = 16
    Top = 128
    Width = 72
    Height = 25
    Caption = 'Ok'
    ModalResult = 1
    TabOrder = 2
  end
  object Button2: TButton
    Left = 104
    Top = 128
    Width = 72
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object Button3: TButton
    Left = 192
    Top = 128
    Width = 72
    Height = 25
    Caption = 'Help'
    TabOrder = 4
    OnClick = Button3Click
  end
  object cxFontNameComboBox1: TcxFontNameComboBox
    Left = 16
    Top = 32
    Style.BorderStyle = ebs3D
    StyleDisabled.BorderStyle = ebsUltraFlat
    StyleFocused.BorderStyle = ebs3D
    StyleHot.BorderStyle = ebs3D
    TabOrder = 5
    Width = 249
  end
end
