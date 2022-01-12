object NewCONISSSheetForm: TNewCONISSSheetForm
  Left = 1216
  Top = 323
  BorderStyle = bsDialog
  Caption = 'CONISS Worrksheet'
  ClientHeight = 256
  ClientWidth = 312
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object RadioGroup1: TRadioGroup
    Left = 16
    Top = 16
    Width = 121
    Height = 65
    Hint = 
      'Choose Data sheet unless there is a specific reason to select th' +
      'e Percents sheet.'
    Caption = 'Transfer Data From:'
    ItemIndex = 0
    Items.Strings = (
      'Data Sheet'
      'Percents Sheet')
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    OnClick = RadioGroup1Click
  end
  object Button1: TButton
    Left = 72
    Top = 216
    Width = 75
    Height = 25
    Caption = 'Ok'
    ModalResult = 1
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 168
    Top = 216
    Width = 75
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object GroupBox1: TGroupBox
    Left = 152
    Top = 16
    Width = 146
    Height = 185
    Caption = 'Groups included in analysis'
    Color = clBtnFace
    ParentColor = False
    TabOrder = 2
    object cxCheckListBox1: TcxCheckListBox
      Left = 2
      Top = 16
      Width = 142
      Height = 167
      Align = alClient
      Items = <>
      Style.BorderColor = clBtnFace
      Style.BorderStyle = cbsNone
      Style.Color = clBtnFace
      Style.Edges = []
      TabOrder = 0
    end
  end
  object GroupBox2: TGroupBox
    Left = 16
    Top = 88
    Width = 121
    Height = 113
    Caption = 'Minimum Values:'
    TabOrder = 4
    object LabeledEdit1: TLabeledEdit
      Left = 8
      Top = 80
      Width = 105
      Height = 21
      Color = clBtnFace
      EditLabel.Width = 73
      EditLabel.Height = 13
      EditLabel.Caption = 'Minimum Value:'
      TabOrder = 0
    end
    object CheckBox1: TCheckBox
      Left = 8
      Top = 16
      Width = 97
      Height = 17
      Caption = 'Data Sheet'
      TabOrder = 1
      OnClick = CheckBox1Click
    end
    object CheckBox2: TCheckBox
      Left = 8
      Top = 40
      Width = 97
      Height = 17
      Caption = 'Percents Sheet'
      TabOrder = 2
      OnClick = CheckBox2Click
    end
  end
end
