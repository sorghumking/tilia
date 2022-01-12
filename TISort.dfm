object SortForm: TSortForm
  Left = 358
  Top = 226
  BorderStyle = bsDialog
  Caption = 'Sort'
  ClientHeight = 203
  ClientWidth = 466
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object CheckBox1: TCheckBox
    Left = 24
    Top = 16
    Width = 97
    Height = 17
    Caption = 'Sort Samples'
    TabOrder = 0
  end
  object CheckBox2: TCheckBox
    Left = 168
    Top = 16
    Width = 97
    Height = 17
    Caption = 'Sort Variables'
    TabOrder = 1
  end
  object Panel1: TPanel
    Left = 16
    Top = 40
    Width = 121
    Height = 57
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    object RadioButton1: TRadioButton
      Left = 8
      Top = 8
      Width = 105
      Height = 17
      Caption = 'Sample Numbers'
      TabOrder = 0
    end
    object RadioButton2: TRadioButton
      Left = 8
      Top = 32
      Width = 105
      Height = 17
      Caption = 'Sample Names'
      TabOrder = 1
    end
  end
  object Panel2: TPanel
    Left = 160
    Top = 40
    Width = 289
    Height = 150
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 3
    object SpeedButton1: TSpeedButton
      Left = 248
      Top = 24
      Width = 25
      Height = 25
      Glyph.Data = {
        72010000424D7201000000000000760000002800000015000000150000000100
        040000000000FC00000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        7777777770007777777777777777777770007777777777777777777770007777
        7777888888877777700077777770000000877777700077777770788880877777
        700077777770F77780877777700077777770F77780877777700077777770F777
        80877777700077777770F77780888887700077700000F7777000007770007777
        0F777777777807777000777770F777777780777770007777770F777778077777
        700077777770F777807777777000777777770F78077777777000777777777070
        7777777770007777777777077777777770007777777777777777777770007777
        77777777777777777000777777777777777777777000}
    end
    object SpeedButton2: TSpeedButton
      Left = 248
      Top = 48
      Width = 25
      Height = 25
      Glyph.Data = {
        72010000424D7201000000000000760000002800000015000000150000000100
        040000000000FC00000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        7777777770007777777777777777777770007777777777787777777770007777
        7777770887777777700077777777708088777777700077777777077808877777
        7000777777707777808877777000777777077777780887777000777770777777
        77808877700077770FFF777778780887700077700000F7778000007770007777
        7770F77780877777700077777770F77780877777700077777770F77780877777
        700077777770F77780877777700077777770FFFF708777777000777777700000
        0077777770007777777777777777777770007777777777777777777770007777
        77777777777777777000777777777777777777777000}
    end
    object Label1: TLabel
      Left = 120
      Top = 8
      Width = 61
      Height = 13
      Caption = 'Group Order:'
    end
    object RadioButton3: TRadioButton
      Left = 8
      Top = 8
      Width = 97
      Height = 17
      Caption = 'Variable Codes'
      TabOrder = 0
    end
    object RadioButton4: TRadioButton
      Left = 8
      Top = 32
      Width = 97
      Height = 17
      Caption = 'Variable Names'
      TabOrder = 1
    end
    object RadioButton5: TRadioButton
      Left = 8
      Top = 56
      Width = 73
      Height = 17
      Caption = 'Groups'
      TabOrder = 2
    end
    object ListBox1: TListBox
      Left = 120
      Top = 24
      Width = 121
      Height = 113
      ItemHeight = 13
      TabOrder = 3
    end
  end
  object Button1: TButton
    Left = 16
    Top = 128
    Width = 75
    Height = 25
    Caption = 'Ok'
    ModalResult = 1
    TabOrder = 4
  end
  object Button2: TButton
    Left = 16
    Top = 160
    Width = 75
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 5
  end
end
