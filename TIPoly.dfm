object PolynomialOptionsForm: TPolynomialOptionsForm
  Left = 381
  Top = 371
  BorderStyle = bsDialog
  Caption = 'Polynomial Options'
  ClientHeight = 174
  ClientWidth = 274
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 39
    Height = 13
    Caption = 'Degree:'
  end
  object cxSpinEdit1: TcxSpinEdit
    Left = 16
    Top = 32
    Properties.MaxValue = 10.000000000000000000
    Properties.MinValue = 1.000000000000000000
    Style.BorderStyle = ebs3D
    TabOrder = 0
    Value = 1
    Width = 65
  end
  object Button1: TButton
    Left = 56
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Ok'
    ModalResult = 1
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 152
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 2
  end
  object Panel1: TPanel
    Left = 112
    Top = 16
    Width = 153
    Height = 65
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 3
    object CheckBox1: TCheckBox
      Left = 8
      Top = 8
      Width = 97
      Height = 17
      Caption = 'Fix minimum age'
      TabOrder = 0
      OnClick = CheckBox1Click
    end
    object LabeledEdit1: TLabeledEdit
      Left = 76
      Top = 32
      Width = 65
      Height = 21
      Color = clBtnFace
      EditLabel.Width = 65
      EditLabel.Height = 13
      EditLabel.Caption = 'Minimum age:'
      Enabled = False
      LabelPosition = lpLeft
      TabOrder = 1
    end
  end
  object CheckBox2: TCheckBox
    Left = 16
    Top = 96
    Width = 193
    Height = 17
    Caption = 'Fit to only dates within depth limits'
    TabOrder = 4
  end
end
