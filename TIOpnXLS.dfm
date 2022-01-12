object ImportExcelForm: TImportExcelForm
  Left = 1464
  Top = 366
  BorderStyle = bsDialog
  Caption = 'Import Excel File'
  ClientHeight = 252
  ClientWidth = 208
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 87
    Height = 13
    Caption = 'Import Worksheet'
  end
  object cxCheckListBox1: TcxCheckListBox
    Left = 16
    Top = 24
    Width = 177
    Height = 153
    Items = <>
    Style.BorderStyle = cbsFlat
    TabOrder = 0
    OnClick = cxCheckListBox1Click
  end
  object CheckBox1: TCheckBox
    Left = 16
    Top = 184
    Width = 137
    Height = 17
    Caption = 'Convert nulls to zeros'
    Checked = True
    State = cbChecked
    TabOrder = 1
  end
  object cxButton1: TcxButton
    Left = 24
    Top = 216
    Width = 75
    Height = 25
    Caption = 'Ok'
    LookAndFeel.Kind = lfOffice11
    ModalResult = 1
    TabOrder = 2
    OnClick = cxButton1Click
  end
  object cxButton2: TcxButton
    Left = 110
    Top = 216
    Width = 75
    Height = 25
    Caption = 'Cancel'
    LookAndFeel.Kind = lfOffice11
    ModalResult = 2
    TabOrder = 3
  end
end
