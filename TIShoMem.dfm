object ShowMemoForm: TShowMemoForm
  Left = 0
  Top = 0
  Caption = 'Memo'
  ClientHeight = 215
  ClientWidth = 406
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 168
    Width = 406
    Height = 47
    Align = alBottom
    BevelEdges = []
    BevelOuter = bvNone
    TabOrder = 0
    OnResize = Panel1Resize
    object FlowPanel1: TFlowPanel
      Left = 74
      Top = 12
      Width = 258
      Height = 25
      AutoSize = True
      AutoWrap = False
      BevelOuter = bvNone
      Locked = True
      TabOrder = 0
      object cxButton1: TcxButton
        Left = 0
        Top = 0
        Width = 86
        Height = 25
        Caption = '&Close'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 11
        TabOrder = 0
      end
      object cxButton2: TcxButton
        Left = 86
        Top = 0
        Width = 86
        Height = 25
        Caption = 'Copy &Selection'
        LookAndFeel.Kind = lfOffice11
        TabOrder = 1
        OnClick = cxButton2Click
      end
      object cxButton3: TcxButton
        Left = 172
        Top = 0
        Width = 86
        Height = 25
        Caption = 'Copy &All'
        LookAndFeel.Kind = lfOffice11
        TabOrder = 2
        OnClick = cxButton3Click
      end
    end
  end
  object cxRichEdit1: TcxRichEdit
    Left = 0
    Top = 0
    Align = alClient
    Properties.ScrollBars = ssBoth
    TabOrder = 1
    ExplicitLeft = 104
    ExplicitTop = 88
    ExplicitWidth = 185
    ExplicitHeight = 89
    Height = 168
    Width = 406
  end
end
