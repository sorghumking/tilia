object ConfirmNoUnitsForm: TConfirmNoUnitsForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Confirm No Units'
  ClientHeight = 348
  ClientWidth = 318
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
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 318
    Height = 69
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 4
    object Label2: TLabel
      Left = 8
      Top = 48
      Width = 238
      Height = 13
      Caption = 'Has variables with the following units in Neotoma:'
    end
    object LabeledEdit1: TLabeledEdit
      Left = 8
      Top = 23
      Width = 301
      Height = 21
      EditLabel.Width = 34
      EditLabel.Height = 13
      EditLabel.Caption = 'Taxon:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
    end
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 211
    Width = 301
    Height = 82
    Caption = 'Confirmation:'
    Items.Strings = (
      'Variable should have units checked above'
      'Variable should have units, but are not in list above'
      'Variable does not have units')
    TabOrder = 1
    OnClick = RadioGroup1Click
  end
  object cxCheckListBox1: TcxCheckListBox
    Left = 0
    Top = 69
    Width = 318
    Height = 136
    Align = alTop
    Items = <>
    Style.BorderStyle = cbsFlat
    TabOrder = 0
    OnClickCheck = cxCheckListBox1ClickCheck
  end
  object cxButton1: TcxButton
    Left = 97
    Top = 308
    Width = 57
    Height = 25
    Caption = 'Ok'
    LookAndFeel.Kind = lfOffice11
    ModalResult = 1
    TabOrder = 2
    OnClick = cxButton1Click
  end
  object cxButton2: TcxButton
    Left = 170
    Top = 308
    Width = 57
    Height = 25
    Caption = 'Cancel'
    LookAndFeel.Kind = lfOffice11
    ModalResult = 2
    TabOrder = 3
  end
end
