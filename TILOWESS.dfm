object LOWESSOptionsForm: TLOWESSOptionsForm
  Left = 474
  Top = 175
  BorderStyle = bsDialog
  Caption = 'LOWESS Options'
  ClientHeight = 208
  ClientWidth = 233
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnActivate = FormActivate
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 16
    Top = 132
    Width = 27
    Height = 13
    Caption = 'Steps'
  end
  object cxSpinEdit2: TcxSpinEdit
    Left = 48
    Top = 128
    Properties.AssignedValues.MinValue = True
    Properties.MaxValue = 5.000000000000000000
    Style.BorderStyle = ebs3D
    Style.ButtonStyle = btsDefault
    TabOrder = 1
    Value = 2
    Width = 65
  end
  object Button1: TButton
    Left = 36
    Top = 168
    Width = 73
    Height = 25
    Caption = 'Ok'
    ModalResult = 1
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 124
    Top = 168
    Width = 73
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object RadioGroup1: TRadioGroup
    Left = 16
    Top = 8
    Width = 204
    Height = 105
    Caption = 'Smoothing Method'
    ItemIndex = 0
    Items.Strings = (
      'Proportion of points'
      'Depth window'
      'Age window')
    TabOrder = 4
    OnClick = RadioGroup1Click
  end
  object cxSpinEdit1: TcxSpinEdit
    Left = 144
    Top = 24
    Properties.Increment = 0.050000000000000000
    Properties.MaxValue = 0.950000000000000000
    Properties.MinValue = 0.050000000000000000
    Properties.ValueType = vtFloat
    Style.BorderStyle = ebs3D
    Style.ButtonStyle = btsDefault
    TabOrder = 0
    Value = 0.500000000000000000
    Width = 65
  end
  object Edit1: TEdit
    Left = 144
    Top = 54
    Width = 65
    Height = 21
    Color = clBtnFace
    Enabled = False
    TabOrder = 5
  end
  object Edit2: TEdit
    Left = 144
    Top = 84
    Width = 65
    Height = 21
    Color = clBtnFace
    Enabled = False
    TabOrder = 6
  end
end
