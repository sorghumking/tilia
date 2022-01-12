object ItalicsForm: TItalicsForm
  Left = 401
  Top = 436
  HelpContext = 122
  BorderIcons = [biSystemMenu, biHelp]
  BorderStyle = bsDialog
  Caption = 'Italicize'
  ClientHeight = 129
  ClientWidth = 327
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poOwnerFormCenter
  ShowHint = True
  OnActivate = FormActivate
  OnHelp = FormHelp
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 32
    Top = 32
    Width = 81
    Height = 25
    Hint = 'Italicize selected text'
    HelpContext = 122
    Caption = '&Italicize'
    ModalResult = 1
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 128
    Top = 32
    Width = 81
    Height = 25
    Hint = 'Remove italics from selected text'
    HelpContext = 122
    Caption = '&Remove Italics'
    ModalResult = 1
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 224
    Top = 32
    Width = 81
    Height = 25
    Hint = 'Automatically italicize genus and species names'
    HelpContext = 122
    Caption = '&Auto Italics'
    ModalResult = 1
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 80
    Top = 80
    Width = 81
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object Button5: TButton
    Left = 176
    Top = 80
    Width = 81
    Height = 25
    Caption = '&Help'
    TabOrder = 4
    OnClick = Button5Click
  end
end
