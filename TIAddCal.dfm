object AddCalibProgForm: TAddCalibProgForm
  Left = 1593
  Top = 206
  BorderStyle = bsToolWindow
  Caption = 'Add Calibration Program'
  ClientHeight = 101
  ClientWidth = 248
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object LabeledEdit1: TLabeledEdit
    Left = 16
    Top = 32
    Width = 105
    Height = 21
    EditLabel.Width = 40
    EditLabel.Height = 13
    EditLabel.Caption = 'Program'
    TabOrder = 0
  end
  object LabeledEdit2: TLabeledEdit
    Left = 128
    Top = 32
    Width = 105
    Height = 21
    EditLabel.Width = 35
    EditLabel.Height = 13
    EditLabel.Caption = 'Version'
    TabOrder = 1
  end
  object cxButton1: TcxButton
    Left = 56
    Top = 64
    Width = 57
    Height = 25
    Caption = 'Ok'
    LookAndFeel.Kind = lfOffice11
    ModalResult = 1
    TabOrder = 2
    OnClick = cxButton1Click
  end
  object cxButton2: TcxButton
    Left = 136
    Top = 64
    Width = 57
    Height = 25
    Caption = 'Cancel'
    LookAndFeel.Kind = lfOffice11
    ModalResult = 2
    TabOrder = 3
  end
end
