object PlotModsForm: TPlotModsForm
  Left = 1222
  Top = 296
  BorderStyle = bsDialog
  Caption = 'Diagram Variable Options'
  ClientHeight = 264
  ClientWidth = 496
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object RadioGroup1: TRadioGroup
    Left = 368
    Top = 16
    Width = 97
    Height = 105
    Caption = 'Separator'
    ItemIndex = 0
    Items.Strings = (
      'None'
      'Colon'
      'Comma'
      'Hyphen'
      'Parentheses')
    TabOrder = 0
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 16
    Width = 129
    Height = 169
    Caption = 'Elements'
    Color = clBtnFace
    ParentColor = False
    TabOrder = 1
    object CheckListBox1: TCheckListBox
      Left = 2
      Top = 16
      Width = 125
      Height = 151
      Align = alClient
      BorderStyle = bsNone
      ItemHeight = 13
      TabOrder = 0
    end
  end
  object Button1: TButton
    Left = 168
    Top = 232
    Width = 75
    Height = 25
    Caption = 'Ok'
    ModalResult = 1
    TabOrder = 2
  end
  object Button2: TButton
    Left = 256
    Top = 232
    Width = 75
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object GroupBox2: TGroupBox
    Left = 152
    Top = 16
    Width = 129
    Height = 169
    Caption = 'Contexts'
    Color = clBtnFace
    ParentColor = False
    TabOrder = 4
    object CheckListBox2: TCheckListBox
      Left = 2
      Top = 16
      Width = 125
      Height = 151
      Align = alClient
      BorderStyle = bsNone
      ItemHeight = 13
      TabOrder = 0
    end
  end
end
