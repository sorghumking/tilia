object ErrorListForm: TErrorListForm
  Left = 363
  Top = 361
  BorderIcons = [biSystemMenu]
  Caption = 'Error List'
  ClientHeight = 295
  ClientWidth = 485
  Color = clBtnFace
  ParentFont = True
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000008
    8888888888888888888888888800008444444444000004444444404447800BB3
    333333333333333333333BB344808BBBBBBBBBBBBBBBBBBBBBBBBBBB1480BBBB
    BBBBBBBBB333BBBBBBBBBBBB3480BBBBBBBBBBBB00483BBBBBBBBBBB14008BBB
    BBBBBBBB00443BBBBBBBBBBB48000BBBBBBBBBBB00003BBBBBBBBBB3480008BB
    BBBBBBBB3000BBBBBBBBBBB4800000BBBBBBBBBBBBBBBBBBBBBBBB340000008B
    BBBBBBBBBB3BBBBBBBBBBB480000000BBBBBBBBBBB0BBBBBBBBBB34000000008
    BBBBBBBBB30BBBBBBBBBB48000000000BBBBBBBBB343BBBBBBBB340000000000
    8BBBBBBBB143BBBBBBBB4800000000000BBBBBBBB073BBBBBBB3480000000000
    08BBBBBBB050BBBBBBB470000000000000BBBBBB3040BBBBBB34800000000000
    008BBBBB10003BBBBB47000000000000000BBBBB00003BBBB348000000000000
    0008BBBB00001BBBB0700000000000000000BBBB00001BBB3480000000000000
    00008BBB3000BBBB070000000000000000000BBBBBBBBBB34800000000000000
    00000BBBBBBBBBB07000000000000000000000BBBBBBBBB48000000000000000
    0000008BBBBBBB0700000000000000000000000BBBBBBB480000000000000000
    0000000BBBBBB370000000000000000000000000BBBBB8000000000000000000
    000000008BBB800000000000000000000000000000800000000000000000E000
    0003C00000018000000100000001000000010000000300000003800000038000
    0007C000000FC000000FE000001FE000001FF000003FF000003FF800003FF800
    007FFC00007FFC0000FFFE0000FFFE0001FFFF0001FFFF0003FFFF8003FFFF80
    07FFFFC007FFFFC00FFFFFE00FFFFFE01FFFFFF03FFFFFF07FFFFFFDFFFF}
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 485
    Height = 249
    Align = alTop
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 2
    WordWrap = False
  end
  object Button1: TButton
    Left = 136
    Top = 264
    Width = 100
    Height = 25
    Caption = 'Make Changes'
    ModalResult = 1
    TabOrder = 0
    Visible = False
  end
  object Button2: TButton
    Left = 256
    Top = 264
    Width = 100
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
    Visible = False
  end
end
