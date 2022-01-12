object InfluxForm: TInfluxForm
  Left = 1303
  Top = 287
  BorderStyle = bsDialog
  Caption = 'Influx'
  ClientHeight = 318
  ClientWidth = 409
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 96
    Width = 80
    Height = 13
    Caption = 'Use Chronology:'
  end
  object Label2: TLabel
    Left = 16
    Top = 184
    Width = 59
    Height = 13
    Caption = 'Use Depths:'
  end
  object RadioGroup1: TRadioGroup
    Left = 16
    Top = 16
    Width = 201
    Height = 65
    Caption = 'Method'
    ItemIndex = 0
    Items.Strings = (
      'Calculate Deposition Time'
      'Use Deposition Time in Data Sheet')
    TabOrder = 0
    OnClick = RadioGroup1Click
  end
  object cxCheckListBox1: TcxCheckListBox
    Left = 16
    Top = 112
    Width = 377
    Height = 65
    Items = <>
    Style.BorderStyle = cbs3D
    TabOrder = 3
    OnClickCheck = cxCheckListBox1ClickCheck
  end
  object RadioGroup2: TRadioGroup
    Left = 224
    Top = 16
    Width = 89
    Height = 65
    Caption = 'Depth Units:'
    ItemIndex = 0
    Items.Strings = (
      'centimetres'
      'metres')
    TabOrder = 1
  end
  object Button1: TButton
    Left = 128
    Top = 280
    Width = 75
    Height = 25
    Caption = 'Ok'
    ModalResult = 1
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 216
    Top = 280
    Width = 75
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 6
  end
  object cxCheckListBox2: TcxCheckListBox
    Left = 16
    Top = 200
    Width = 377
    Height = 65
    Items = <>
    Style.BorderStyle = cbs3D
    TabOrder = 4
    OnClickCheck = cxCheckListBox2ClickCheck
  end
  object RadioGroup3: TRadioGroup
    Left = 320
    Top = 16
    Width = 73
    Height = 65
    Caption = 'Null Values:'
    ItemIndex = 0
    Items.Strings = (
      'Skip'
      'Zero')
    TabOrder = 2
  end
end
