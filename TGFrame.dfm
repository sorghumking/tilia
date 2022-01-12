object FrameForm: TFrameForm
  Left = 486
  Top = 330
  Hint = 'Frame form'
  HelpContext = 123
  BorderIcons = [biSystemMenu, biHelp]
  BorderStyle = bsDialog
  Caption = 'Diagram Frame'
  ClientHeight = 265
  ClientWidth = 352
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  ShowHint = True
  OnActivate = FormActivate
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnHelp = FormHelp
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 64
    Top = 224
    Width = 65
    Height = 25
    Caption = '&Ok'
    ModalResult = 1
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 144
    Top = 224
    Width = 65
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object Button3: TButton
    Left = 224
    Top = 224
    Width = 65
    Height = 25
    Caption = '&Help'
    TabOrder = 4
    OnClick = Button3Click
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 16
    Width = 153
    Height = 193
    Hint = 'Frame'
    Caption = 'Frame'
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 92
      Width = 54
      Height = 13
      Caption = 'Line Width:'
      FocusControl = LineWidthComboBox1
    end
    object Label2: TLabel
      Left = 8
      Top = 136
      Width = 29
      Height = 13
      Caption = 'Color:'
      FocusControl = ColorBox1
    end
    object CheckBox1: TCheckBox
      Left = 8
      Top = 24
      Width = 97
      Height = 17
      Hint = 'Check this box to draw a frame around the diagram'
      HelpContext = 124
      Caption = 'Draw Frame'
      TabOrder = 0
      OnClick = CheckBox1Click
    end
    object LineWidthComboBox1: TComboBox
      Left = 8
      Top = 108
      Width = 97
      Height = 21
      Hint = 'Frame line width'
      HelpContext = 6
      TabOrder = 2
    end
    object ColorBox1: TColorBox
      Left = 8
      Top = 152
      Width = 129
      Height = 22
      Hint = 'Frame color'
      HelpContext = 7
      Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
      TabOrder = 3
    end
    object LabeledEdit5: TLabeledEdit
      Left = 8
      Top = 64
      Width = 97
      Height = 21
      Hint = 'Distance between the frame and the diagram in virtual units'
      HelpContext = 125
      EditLabel.Width = 69
      EditLabel.Height = 13
      EditLabel.Caption = 'Frame Margin:'
      TabOrder = 1
    end
  end
  object GroupBox2: TGroupBox
    Left = 184
    Top = 16
    Width = 153
    Height = 161
    Hint = 'Margins between diagram and edge of the page'
    HelpContext = 126
    Caption = 'Page Margins'
    TabOrder = 1
    object LabeledEdit1: TLabeledEdit
      Left = 48
      Top = 24
      Width = 89
      Height = 21
      Hint = 'Top margin'
      HelpContext = 126
      EditLabel.Width = 22
      EditLabel.Height = 13
      EditLabel.Caption = 'Top:'
      LabelPosition = lpLeft
      TabOrder = 0
    end
    object LabeledEdit2: TLabeledEdit
      Left = 48
      Top = 56
      Width = 89
      Height = 21
      Hint = 'Bottom margin'
      HelpContext = 126
      EditLabel.Width = 38
      EditLabel.Height = 13
      EditLabel.Caption = 'Bottom:'
      LabelPosition = lpLeft
      TabOrder = 1
    end
    object LabeledEdit3: TLabeledEdit
      Left = 48
      Top = 88
      Width = 89
      Height = 21
      Hint = 'Left margin'
      HelpContext = 126
      EditLabel.Width = 23
      EditLabel.Height = 13
      EditLabel.Caption = 'Left:'
      LabelPosition = lpLeft
      TabOrder = 2
    end
    object LabeledEdit4: TLabeledEdit
      Left = 48
      Top = 120
      Width = 89
      Height = 21
      Hint = 'Right margin'
      HelpContext = 126
      EditLabel.Width = 29
      EditLabel.Height = 13
      EditLabel.Caption = 'Right:'
      LabelPosition = lpLeft
      TabOrder = 3
    end
  end
end
