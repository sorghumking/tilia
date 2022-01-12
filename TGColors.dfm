object ColorsForm: TColorsForm
  Left = 405
  Top = 179
  HelpContext = 114
  BorderIcons = [biSystemMenu, biMinimize, biMaximize, biHelp]
  BorderStyle = bsDialog
  Caption = 'Colors'
  ClientHeight = 381
  ClientWidth = 256
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  ShowHint = True
  OnActivate = FormActivate
  OnHelp = FormHelp
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 144
    Top = 20
    Width = 56
    Height = 13
    Caption = 'Background'
    FocusControl = ColorBox1
  end
  object Label2: TLabel
    Left = 144
    Top = 44
    Width = 29
    Height = 13
    Caption = 'Graph'
    FocusControl = ColorBox2
  end
  object Label3: TLabel
    Left = 144
    Top = 68
    Width = 66
    Height = 13
    Caption = 'Graph Outline'
    FocusControl = ColorBox3
  end
  object Label4: TLabel
    Left = 144
    Top = 92
    Width = 64
    Height = 13
    Caption = 'Exaggeration'
    FocusControl = ColorBox4
  end
  object Label5: TLabel
    Left = 144
    Top = 116
    Width = 101
    Height = 13
    Caption = 'Exaggeration Outline'
    FocusControl = ColorBox5
  end
  object Label6: TLabel
    Left = 144
    Top = 140
    Width = 53
    Height = 13
    Caption = 'Depth Bars'
    FocusControl = ColorBox6
  end
  object Label7: TLabel
    Left = 144
    Top = 164
    Width = 24
    Height = 13
    Caption = 'Axes'
    FocusControl = ColorBox7
  end
  object Label8: TLabel
    Left = 144
    Top = 188
    Width = 29
    Height = 13
    Caption = 'Zones'
    FocusControl = ColorBox8
  end
  object Label9: TLabel
    Left = 144
    Top = 212
    Width = 34
    Height = 13
    Caption = 'Groups'
    FocusControl = ColorBox9
  end
  object Label10: TLabel
    Left = 144
    Top = 236
    Width = 28
    Height = 13
    Caption = 'Dates'
    FocusControl = ColorBox10
  end
  object Label11: TLabel
    Left = 144
    Top = 260
    Width = 22
    Height = 13
    Caption = 'Text'
    FocusControl = ColorBox11
  end
  object Label12: TLabel
    Left = 144
    Top = 284
    Width = 43
    Height = 13
    Caption = 'Lithology'
  end
  object Label13: TLabel
    Left = 144
    Top = 308
    Width = 59
    Height = 13
    Caption = 'Dendrogram'
  end
  object ColorBox1: TColorBox
    Left = 16
    Top = 16
    Width = 121
    Height = 22
    Hint = 'Background color'
    HelpContext = 7
    Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
    TabOrder = 0
    OnChange = ColorBox1Change
  end
  object ColorBox2: TColorBox
    Left = 16
    Top = 40
    Width = 121
    Height = 22
    Hint = 'Graph color'
    HelpContext = 7
    Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
    TabOrder = 1
    OnChange = ColorBox2Change
  end
  object ColorBox3: TColorBox
    Left = 16
    Top = 64
    Width = 121
    Height = 22
    Hint = 'Graph outline color'
    HelpContext = 7
    Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
    TabOrder = 2
    OnChange = ColorBox3Change
  end
  object ColorBox4: TColorBox
    Left = 16
    Top = 88
    Width = 121
    Height = 22
    Hint = 'Graph exaggeration color'
    HelpContext = 7
    Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
    TabOrder = 3
    OnChange = ColorBox4Change
  end
  object ColorBox5: TColorBox
    Left = 16
    Top = 112
    Width = 121
    Height = 22
    Hint = 'Graph exaggeration outline color'
    HelpContext = 7
    Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
    TabOrder = 4
    OnChange = ColorBox5Change
  end
  object ColorBox6: TColorBox
    Left = 16
    Top = 136
    Width = 121
    Height = 22
    Hint = 'Depth bars color'
    HelpContext = 7
    Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
    TabOrder = 5
    OnChange = ColorBox6Change
  end
  object ColorBox7: TColorBox
    Left = 16
    Top = 160
    Width = 121
    Height = 22
    Hint = 'Axes color'
    HelpContext = 7
    Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
    TabOrder = 6
    OnChange = ColorBox7Change
  end
  object ColorBox8: TColorBox
    Left = 16
    Top = 184
    Width = 121
    Height = 22
    Hint = 'Zones color'
    HelpContext = 7
    Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
    TabOrder = 7
    OnChange = ColorBox8Change
  end
  object ColorBox9: TColorBox
    Left = 16
    Top = 208
    Width = 121
    Height = 22
    Hint = 'Groups color'
    HelpContext = 7
    Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
    TabOrder = 8
    OnChange = ColorBox9Change
  end
  object ColorBox10: TColorBox
    Left = 16
    Top = 232
    Width = 121
    Height = 22
    Hint = 'Dates color'
    HelpContext = 7
    Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
    TabOrder = 9
    OnChange = ColorBox10Change
  end
  object ColorBox11: TColorBox
    Left = 16
    Top = 256
    Width = 121
    Height = 22
    Hint = 'Text color'
    HelpContext = 7
    Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
    TabOrder = 10
    OnChange = ColorBox11Change
  end
  object ColorBox12: TColorBox
    Left = 16
    Top = 280
    Width = 121
    Height = 22
    Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
    TabOrder = 11
    OnChange = ColorBox12Change
  end
  object ColorBox13: TColorBox
    Left = 16
    Top = 304
    Width = 121
    Height = 22
    Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
    TabOrder = 12
    OnChange = ColorBox13Change
  end
  object cxButton1: TcxButton
    Left = 176
    Top = 344
    Width = 65
    Height = 25
    Caption = '&Help'
    LookAndFeel.Kind = lfOffice11
    TabOrder = 13
    OnClick = cxButton1Click
  end
  object cxButton2: TcxButton
    Left = 16
    Top = 344
    Width = 65
    Height = 25
    Caption = '&Ok'
    LookAndFeel.Kind = lfOffice11
    ModalResult = 1
    TabOrder = 14
    OnClick = cxButton2Click
  end
  object cxButton3: TcxButton
    Left = 96
    Top = 344
    Width = 65
    Height = 25
    Caption = '&Cancel'
    LookAndFeel.Kind = lfOffice11
    ModalResult = 2
    TabOrder = 15
  end
  object ColorDialog1: TColorDialog
    Left = 208
    Top = 248
  end
end
