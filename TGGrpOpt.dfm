object GroupOptionsForm: TGroupOptionsForm
  Left = 544
  Top = 219
  BorderIcons = [biSystemMenu, biHelp]
  BorderStyle = bsDialog
  Caption = 'Group Options'
  ClientHeight = 210
  ClientWidth = 257
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poOwnerFormCenter
  ShowHint = True
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnHelp = FormHelp
  PixelsPerInch = 96
  TextHeight = 13
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 16
    Width = 97
    Height = 65
    Hint = 'Text position'
    HelpContext = 77
    Caption = 'Text Position'
    Items.Strings = (
      'In Line'
      'Above Line')
    TabOrder = 0
  end
  object GroupBox2: TGroupBox
    Left = 112
    Top = 16
    Width = 137
    Height = 109
    Caption = 'Lines'
    TabOrder = 1
    object Label1: TLabel
      Left = 8
      Top = 16
      Width = 32
      Height = 13
      Caption = 'Width:'
    end
    object Label3: TLabel
      Left = 8
      Top = 60
      Width = 29
      Height = 13
      Caption = 'Color:'
    end
    object LineWidthComboBox1: TComboBox
      Left = 8
      Top = 32
      Width = 97
      Height = 21
      Hint = 'Line width'
      HelpContext = 6
      TabOrder = 0
    end
    object ColorBox2: TColorBox
      Left = 8
      Top = 76
      Width = 121
      Height = 22
      Hint = 'Color'
      HelpContext = 7
      Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
      TabOrder = 1
    end
  end
  object Button4: TButton
    Left = 16
    Top = 168
    Width = 65
    Height = 25
    Caption = '&Ok'
    ModalResult = 1
    TabOrder = 2
  end
  object Button5: TButton
    Left = 96
    Top = 168
    Width = 65
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object Button6: TButton
    Left = 176
    Top = 168
    Width = 65
    Height = 25
    Caption = '&Help'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 4
    OnClick = Button6Click
  end
  object CheckBox1: TCheckBox
    Left = 8
    Top = 136
    Width = 113
    Height = 17
    Hint = 'Check this box to apply to all groups'
    HelpContext = 78
    Caption = 'Apply to all groups'
    TabOrder = 5
  end
  object BitBtn1: TBitBtn
    Left = 8
    Top = 99
    Width = 97
    Height = 25
    Hint = 'Group text font'
    HelpContext = 20
    Caption = 'Font'
    DoubleBuffered = True
    Glyph.Data = {
      F6000000424DF600000000000000760000002800000010000000100000000100
      04000000000080000000CE0E0000D80E00001000000000000000000000000000
      8000008000000080800080000000800080008080000080808000C0C0C0000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
      8888888888888888888888884444488844448888884488888448888888844888
      8448888888884444444888888888844884488088808888448448807870888884
      4448870007888888444888080888888884488808088888888888887078888888
      8888888088888888888888888888888888888888888888888888}
    ParentDoubleBuffered = False
    TabOrder = 6
    OnClick = BitBtn1Click
  end
  object ColorDialog1: TColorDialog
    Left = 200
    Top = 136
  end
end
