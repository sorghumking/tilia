object SortForm: TSortForm
  Left = 1365
  Top = 585
  BorderStyle = bsDialog
  Caption = 'Sort'
  ClientHeight = 226
  ClientWidth = 461
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object CheckBox1: TCheckBox
    Left = 24
    Top = 16
    Width = 97
    Height = 17
    Caption = 'Sort Columns'
    TabOrder = 0
    OnClick = CheckBox1Click
  end
  object CheckBox2: TCheckBox
    Left = 168
    Top = 16
    Width = 97
    Height = 17
    Caption = 'Sort Rows'
    TabOrder = 1
    OnClick = CheckBox2Click
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
      Checked = True
      Enabled = False
      TabOrder = 0
      TabStop = True
    end
    object RadioButton2: TRadioButton
      Left = 8
      Top = 32
      Width = 105
      Height = 17
      Caption = 'Sample Names'
      Enabled = False
      TabOrder = 1
    end
  end
  object Panel2: TPanel
    Left = 160
    Top = 40
    Width = 289
    Height = 177
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 3
    object SpeedButton1: TSpeedButton
      Left = 248
      Top = 24
      Width = 25
      Height = 25
      Enabled = False
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
      Visible = False
      OnClick = SpeedButton1Click
    end
    object SpeedButton2: TSpeedButton
      Left = 248
      Top = 48
      Width = 25
      Height = 25
      Enabled = False
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
      Visible = False
      OnClick = SpeedButton2Click
    end
    object Label1: TLabel
      Left = 120
      Top = 8
      Width = 64
      Height = 13
      Caption = 'Group Order:'
      Enabled = False
      Visible = False
    end
    object RadioButton3: TRadioButton
      Left = 8
      Top = 8
      Width = 57
      Height = 17
      Caption = 'Codes'
      Enabled = False
      TabOrder = 0
      OnClick = RadioButton3Click
    end
    object RadioButton4: TRadioButton
      Left = 8
      Top = 32
      Width = 65
      Height = 17
      Caption = 'Names'
      Checked = True
      Enabled = False
      TabOrder = 1
      TabStop = True
      OnClick = RadioButton4Click
    end
    object RadioButton5: TRadioButton
      Left = 8
      Top = 56
      Width = 73
      Height = 17
      Caption = 'Elements'
      Enabled = False
      TabOrder = 2
      OnClick = RadioButton5Click
    end
    object ListBox1: TListBox
      Left = 120
      Top = 24
      Width = 121
      Height = 137
      Enabled = False
      ItemHeight = 13
      Sorted = True
      TabOrder = 3
      Visible = False
    end
    object RadioButton6: TRadioButton
      Left = 8
      Top = 80
      Width = 81
      Height = 17
      Caption = 'Units'
      Enabled = False
      TabOrder = 4
      OnClick = RadioButton6Click
    end
    object RadioButton7: TRadioButton
      Left = 8
      Top = 104
      Width = 81
      Height = 17
      Caption = 'Contexts'
      Enabled = False
      TabOrder = 5
      OnClick = RadioButton7Click
    end
    object RadioButton8: TRadioButton
      Left = 8
      Top = 128
      Width = 89
      Height = 17
      Caption = 'Taphonomy'
      Enabled = False
      TabOrder = 6
      OnClick = RadioButton8Click
    end
    object RadioButton9: TRadioButton
      Left = 8
      Top = 152
      Width = 81
      Height = 17
      Caption = 'Groups'
      Enabled = False
      TabOrder = 7
      OnClick = RadioButton9Click
    end
  end
  object Button1: TButton
    Left = 16
    Top = 160
    Width = 75
    Height = 25
    Caption = 'Ok'
    ModalResult = 1
    TabOrder = 4
  end
  object Button2: TButton
    Left = 16
    Top = 192
    Width = 75
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 5
  end
end
