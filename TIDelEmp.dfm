object DelEmptyRowColForm: TDelEmptyRowColForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Delete Empty Rows'
  ClientHeight = 145
  ClientWidth = 240
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object CheckBox1: TCheckBox
    Left = 16
    Top = 24
    Width = 193
    Height = 17
    Caption = 'Header columns must be empty'
    TabOrder = 0
  end
  object cxButton1: TcxButton
    Left = 40
    Top = 104
    Width = 75
    Height = 25
    Caption = 'Ok'
    LookAndFeel.Kind = lfOffice11
    LookAndFeel.NativeStyle = False
    ModalResult = 1
    TabOrder = 1
  end
  object cxButton2: TcxButton
    Left = 128
    Top = 104
    Width = 75
    Height = 25
    Caption = 'Cancel'
    LookAndFeel.Kind = lfOffice11
    ModalResult = 2
    TabOrder = 2
  end
  object RadioButton1: TRadioButton
    Left = 16
    Top = 48
    Width = 233
    Height = 17
    Caption = 'Delete rows with all cells empty or zero'
    Checked = True
    TabOrder = 3
    TabStop = True
  end
  object RadioButton2: TRadioButton
    Left = 16
    Top = 71
    Width = 203
    Height = 17
    Caption = 'Delete rows with all cells empty'
    TabOrder = 4
  end
end
