object SSFormatForm: TSSFormatForm
  Left = 418
  Top = 290
  BorderStyle = bsDialog
  Caption = 'Format'
  ClientHeight = 226
  ClientWidth = 215
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object RadioGroup1: TRadioGroup
    Left = 120
    Top = 8
    Width = 89
    Height = 77
    Caption = 'Apply to:'
    ItemIndex = 0
    Items.Strings = (
      'Cell'
      'Selection'
      'Sheet')
    TabOrder = 0
  end
  object CheckBox1: TCheckBox
    Left = 16
    Top = 92
    Width = 90
    Height = 17
    Caption = 'Skip headers'
    TabOrder = 1
  end
  object CheckBox2: TCheckBox
    Left = 120
    Top = 92
    Width = 90
    Height = 17
    Caption = 'Skip metadata'
    TabOrder = 2
  end
  object Button1: TButton
    Left = 32
    Top = 192
    Width = 75
    Height = 25
    Caption = 'Ok'
    ModalResult = 1
    TabOrder = 3
  end
  object Button2: TButton
    Left = 120
    Top = 192
    Width = 75
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 4
  end
  object RadioGroup2: TRadioGroup
    Left = 16
    Top = 8
    Width = 89
    Height = 77
    Caption = 'Format'
    Items.Strings = (
      'Text'
      'Number'
      'Date')
    TabOrder = 6
  end
  object Panel1: TPanel
    Left = 16
    Top = 120
    Width = 193
    Height = 57
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 5
    object Label1: TLabel
      Left = 88
      Top = 8
      Width = 72
      Height = 13
      Caption = 'Decimal points:'
    end
    object cxSpinEdit1: TcxSpinEdit
      Left = 88
      Top = 24
      Properties.MaxValue = 15.000000000000000000
      Style.BorderStyle = ebs3D
      TabOrder = 1
      Width = 81
    end
    object RadioButton1: TRadioButton
      Left = 8
      Top = 8
      Width = 73
      Height = 17
      Caption = 'General'
      TabOrder = 0
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 8
      Top = 28
      Width = 73
      Height = 17
      Caption = 'Decimal'
      TabOrder = 2
      OnClick = RadioButton2Click
    end
  end
end
