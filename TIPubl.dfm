object PubForm: TPubForm
  Left = 435
  Top = 248
  BorderIcons = [biSystemMenu]
  Caption = 'Publication'
  ClientHeight = 477
  ClientWidth = 410
  Color = clBtnFace
  DoubleBuffered = True
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  OnCanResize = FormCanResize
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel17: TPanel
    Left = 0
    Top = 0
    Width = 410
    Height = 41
    Align = alTop
    BevelOuter = bvNone
    Color = 15984090
    ParentBackground = False
    TabOrder = 2
    object cxButton8: TcxButton
      Left = 4
      Top = 10
      Width = 25
      Height = 25
      LookAndFeel.Kind = lfOffice11
      LookAndFeel.NativeStyle = False
      OptionsImage.ImageIndex = 0
      OptionsImage.Images = cxImageList1
      ParentShowHint = False
      ShowHint = False
      TabOrder = 0
      OnClick = NeotomaButtonClick
    end
    object FlowPanel5: TFlowPanel
      Left = 35
      Top = 6
      Width = 375
      Height = 30
      BevelOuter = bvNone
      Color = 15984090
      ParentBackground = False
      TabOrder = 1
      object cxButtonJournal: TcxButton
        Left = 0
        Top = 0
        Width = 48
        Height = 25
        Caption = 'Journal'
        LookAndFeel.Kind = lfOffice11
        LookAndFeel.NativeStyle = False
        SpeedButtonOptions.GroupIndex = 1
        SpeedButtonOptions.Down = True
        TabOrder = 0
        OnClick = cxButtonJournalClick
      end
      object cxButtonBookChapter: TcxButton
        Left = 48
        Top = 0
        Width = 76
        Height = 25
        Caption = 'Book Chapter'
        LookAndFeel.Kind = lfOffice11
        SpeedButtonOptions.GroupIndex = 1
        TabOrder = 1
        OnClick = cxButtonBookChapterClick
      end
      object cxButtonBook: TcxButton
        Left = 124
        Top = 0
        Width = 48
        Height = 25
        Caption = 'Book'
        LookAndFeel.Kind = lfOffice11
        SpeedButtonOptions.GroupIndex = 1
        TabOrder = 2
        OnClick = cxButtonBookClick
      end
      object cxButtonReport: TcxButton
        Left = 172
        Top = 0
        Width = 48
        Height = 25
        Caption = 'Report'
        LookAndFeel.Kind = lfOffice11
        SpeedButtonOptions.GroupIndex = 1
        TabOrder = 3
        OnClick = cxButtonReportClick
      end
      object cxButtonThesis: TcxButton
        Left = 220
        Top = 0
        Width = 48
        Height = 25
        Caption = 'Thesis'
        LookAndFeel.Kind = lfOffice11
        SpeedButtonOptions.GroupIndex = 1
        TabOrder = 4
        OnClick = cxButtonThesisClick
      end
      object cxButtonWebsite: TcxButton
        Left = 268
        Top = 0
        Width = 48
        Height = 25
        Caption = 'Website'
        LookAndFeel.Kind = lfOffice11
        SpeedButtonOptions.GroupIndex = 1
        TabOrder = 5
        OnClick = cxButtonWebsiteClick
      end
      object cxButtonOther: TcxButton
        Left = 316
        Top = 0
        Width = 48
        Height = 25
        Caption = 'Other'
        LookAndFeel.Kind = lfOffice11
        SpeedButtonOptions.GroupIndex = 1
        TabOrder = 6
        OnClick = cxButtonOtherClick
      end
    end
  end
  object Panel18: TPanel
    Left = 0
    Top = 41
    Width = 410
    Height = 369
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object ScrollBox1: TScrollBox
      Left = 0
      Top = 0
      Width = 410
      Height = 369
      VertScrollBar.Range = 1180
      Align = alClient
      AutoScroll = False
      Color = 10841658
      ParentColor = False
      TabOrder = 0
      object FlowPanel2: TFlowPanel
        Left = 0
        Top = 0
        Width = 389
        Height = 1180
        Align = alClient
        BevelOuter = bvNone
        Color = 15984090
        Ctl3D = True
        ParentBackground = False
        ParentCtl3D = False
        TabOrder = 0
        DesignSize = (
          389
          1180)
        object LabelNeotomaPubID: TLabel
          Left = 0
          Top = 0
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Neotoma PublicationID: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          Visible = False
        end
        object Panel10: TPanel
          Left = 124
          Top = 0
          Width = 260
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          BevelOuter = bvNone
          Color = 15984090
          ParentBackground = False
          TabOrder = 32
          Visible = False
          DesignSize = (
            260
            21)
          object cxNeotomaPubIDEdit: TcxTextEdit
            Left = 0
            Top = 0
            ParentFont = False
            Properties.Alignment.Horz = taRightJustify
            Properties.ReadOnly = True
            Style.BorderColor = clNavy
            Style.BorderStyle = ebsSingle
            Style.Color = 15984090
            Style.Font.Charset = DEFAULT_CHARSET
            Style.Font.Color = clNavy
            Style.Font.Height = -11
            Style.Font.Name = 'Tahoma'
            Style.Font.Style = []
            Style.LookAndFeel.Kind = lfOffice11
            Style.TextColor = clNavy
            Style.IsFontAssigned = True
            StyleDisabled.LookAndFeel.Kind = lfOffice11
            StyleFocused.LookAndFeel.Kind = lfOffice11
            StyleHot.LookAndFeel.Kind = lfOffice11
            TabOrder = 0
            OnExit = cxPublisherEditExit
            Width = 65
          end
          object FlowPanel3: TFlowPanel
            Left = 136
            Top = 0
            Width = 124
            Height = 21
            Anchors = [akTop, akRight]
            AutoSize = True
            AutoWrap = False
            BevelOuter = bvNone
            Color = 15984090
            ParentBackground = False
            TabOrder = 1
            Visible = False
            object AdvMultiColumnDropDown1: TAdvMultiColumnDropDown
              Left = 0
              Top = 0
              Width = 40
              Height = 21
              DropDownRowHeight = 18
              LineColor = 15855083
              FixedLineColor = 13745060
              Columns = <
                item
                  Width = 24
                  Alignment = taRightJustify
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'ID'
                  AutoSize = True
                end
                item
                  Font.Charset = DEFAULT_CHARSET
                  Font.Color = clWindowText
                  Font.Height = -11
                  Font.Name = 'Tahoma'
                  Font.Style = []
                  Header = 'Publication Type'
                  AutoSize = True
                end>
              HeaderColor = clWhite
              HeaderColorTo = clGray
              HeaderHeight = 25
              HeaderFont.Charset = DEFAULT_CHARSET
              HeaderFont.Color = 7485192
              HeaderFont.Height = -11
              HeaderFont.Name = 'Tahoma'
              HeaderFont.Style = []
              Items = <>
              ItemIndex = -1
              BevelInner = bvNone
              BevelOuter = bvNone
              ParentShowHint = False
              ShowHint = False
              DropDownBorderColor = clNone
              DropDownHeight = 200
              EditorEnabled = False
              LabelMargin = 0
              LabelFont.Charset = DEFAULT_CHARSET
              LabelFont.Color = clWindowText
              LabelFont.Height = -11
              LabelFont.Name = 'Tahoma'
              LabelFont.Style = []
              Version = '1.4.5.7'
              SelectionColor = 14155773
              SelectionColorTo = 5821692
              ButtonAppearance.BorderColorHot = 10079963
              ButtonAppearance.BorderColorDown = 4370174
              ButtonAppearance.Color = 16773091
              ButtonAppearance.ColorTo = 16768452
              ButtonAppearance.ColorDisabledTo = 11974326
              ButtonAppearance.ColorDown = 11196927
              ButtonAppearance.ColorDownTo = 7257087
              ButtonAppearance.ColorHot = 15465983
              ButtonAppearance.ColorHotTo = 11332863
              ButtonAppearance.Font.Charset = DEFAULT_CHARSET
              ButtonAppearance.Font.Color = clWindowText
              ButtonAppearance.Font.Height = -11
              ButtonAppearance.Font.Name = 'Tahoma'
              ButtonAppearance.Font.Style = []
              DropDownHeader.Color = 16773091
              DropDownHeader.ColorTo = 16765615
              DropDownHeader.Font.Charset = DEFAULT_CHARSET
              DropDownHeader.Font.Color = 7485192
              DropDownHeader.Font.Height = -11
              DropDownHeader.Font.Name = 'Tahoma'
              DropDownHeader.Font.Style = []
              DropDownHeader.Visible = True
              DropDownHeader.BorderColor = 16765615
              DropDownHeader.Buttons = <>
              DropDownFooter.Color = 16773091
              DropDownFooter.ColorTo = 16765615
              DropDownFooter.Font.Charset = DEFAULT_CHARSET
              DropDownFooter.Font.Color = 7485192
              DropDownFooter.Font.Height = -11
              DropDownFooter.Font.Name = 'Tahoma'
              DropDownFooter.Font.Style = []
              DropDownFooter.Visible = True
              DropDownFooter.BorderColor = 16765615
              DropDownFooter.Buttons = <>
              TabOrder = 4
              OnSelect = AdvMultiColumnDropDown1Select
              SelectionColorStyle = 1
              TMSStyle = 4
            end
            object cxButtonFirst: TcxButton
              Left = 40
              Top = 0
              Width = 21
              Height = 21
              Enabled = False
              LookAndFeel.Kind = lfOffice11
              OptionsImage.Glyph.Data = {
                36040000424D3604000000000000360000002800000010000000100000000100
                2000000000000004000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000300000003300000033000000300000000000000000000000000000
                0000000000000000000000000033000000300000000000000000000000000000
                0000AE7C41F2B78343FFB78344FFAE7C41F20000000000000000000000000000
                00000000000000000033B98545FFAF7E42F30000000000000000000000000000
                0000B78243FFFBCE88FFFBCA80FFB78343FF0000000000000000000000000000
                000000000033B68242FFEBBC77FFB88444FF0000000000000000000000000000
                0000B68141FFF4CA8AFFF2C177FFB68242FF0000000000000000000000000000
                0033B68141FFF4CC8CFFE3B574FFB88343FF0000000000000000000000000000
                0000B68141FFF2CB90FFEDBC71FFB68242FF000000000000000000000033B681
                41FFE6C38CFFE5B366FFDFB576FFB88343FF0000000000000000000000000000
                0000B68141FFF0CC95FFE8B66AFFB68243FF0000000000000033B78140FFE6C4
                93FFDFAB5FFFDEAB5FFFDDB57AFFB88342FF0000000000000000000000000000
                0000B68140FFEFCE9DFFE5B164FFB78243FF00000000B98442FFCFB58DF6DCAC
                64FFD7A457FFD7A457FFDCB580FFB88342FF0000000000000000000000000000
                0000B6813FFFEED1A4FFE0AC5DFFB78344FF00000000B98442FFD2B995F6D6A6
                5FFFD29D4FFFD29D4FFFDCB784FFB88342FF0000000000000000000000000000
                0000B6813FFFEFD4ADFFDBA556FFB88344FF0000000000000000B88140FFDCC4
                9FFBCA9444FFCA9444FFDBBA8BFFB88342FF0000000000000000000000000000
                0000B6803FFFEFDAB6FFD6A050FFB88344FF000000000000000000000000B781
                40FFE3CEAAFFC38B38FFDBBC90FFB88241FF0000000000000000000000000000
                0000B6803EFFF1DDC0FFD19846FFB88342FF0000000000000000000000000000
                0000B7813FFFE6CFADFFDDC096FFB88241FF0000000000000000000000000000
                0000B8823FFFF4E5CCFFF4E6CEFFB88241FF0000000000000000000000000000
                000000000000B8813FFFDFC6A4FFB98442FF0000000000000000000000000000
                0000805C2FB0B88240FFB88240FF805C2FB00000000000000000000000000000
                00000000000000000000B98443FF825E30B20000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000}
              ParentShowHint = False
              ShowHint = False
              SpeedButtonOptions.GroupIndex = 1
              TabOrder = 0
              OnClick = cxButtonFirstClick
            end
            object cxButtonPrev: TcxButton
              Left = 61
              Top = 0
              Width = 21
              Height = 21
              Enabled = False
              LookAndFeel.Kind = lfOffice11
              OptionsImage.Glyph.Data = {
                36040000424D3604000000000000360000002800000010000000100000000100
                2000000000000004000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0033000000300000000000000000000000000000000000000000000000000000
                000000000000000000000000000000000000000000000000000000000033B884
                44FFAF7D42F30000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000033B68141FFFCCD
                87FFB88343FF0000000000000000000000000000000000000000000000000000
                00000000000000000000000000000000000000000033B68140FFF3CB8BFFF1C6
                84FFB68242FF0000000000000000000000000000000000000000000000000000
                000000000000000000000000000000000033B68141FFE6C38CFFE4B265FFECC4
                88FFB68241FF0000000000000000000000000000000000000000000000000000
                0000000000000000000000000033B78140FFE6C493FFDFAB5FFFDDAA5EFFEAC5
                8EFFB78241FF0000000000000000000000000000000000000000000000000000
                00000000000000000000B98442FFCFB58DF6DCAC64FFD7A457FFD6A356FFE8C6
                94FFB78241FF0000000000000000000000000000000000000000000000000000
                00000000000000000000B98442FFD2B995F6D6A65FFFD19D4EFFD19C4DFFE6C8
                9AFFB78241FF0000000000000000000000000000000000000000000000000000
                0000000000000000000000000000B88140FFDCC49FFBCA9444FFCA9343FFE7CB
                A3FFB78240FF0000000000000000000000000000000000000000000000000000
                000000000000000000000000000000000000B78140FFE3CEAAFFC28A36FFE6CE
                A9FFB7813FFF0000000000000000000000000000000000000000000000000000
                00000000000000000000000000000000000000000000B7813FFFE5CEABFFE7D3
                B2FFB8813FFF0000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000B7803DFFEBDD
                C3FFB88241FF0000000000000000000000000000000000000000000000000000
                000000000000000000000000000000000000000000000000000000000000B984
                42FF825D30B20000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000}
              ParentShowHint = False
              ShowHint = False
              SpeedButtonOptions.GroupIndex = 1
              TabOrder = 1
              OnClick = cxButtonPrevClick
            end
            object cxButtonNext: TcxButton
              Left = 82
              Top = 0
              Width = 21
              Height = 21
              Enabled = False
              LookAndFeel.Kind = lfOffice11
              OptionsImage.Glyph.Data = {
                36040000424D3604000000000000360000002800000010000000100000000100
                2000000000000004000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000030000000330000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000AF7D42F3B88444FF0000003300000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000B88343FFFCCD87FFB68141FF00000033000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000B68242FFF1C684FFF3CB8BFFB68140FF000000330000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000B68241FFECC488FFE4B265FFE6C38CFFB68141FF0000
                0033000000000000000000000000000000000000000000000000000000000000
                00000000000000000000B78241FFEAC58EFFDDAA5EFFDFAB5FFFE6C493FFB781
                40FF000000330000000000000000000000000000000000000000000000000000
                00000000000000000000B78241FFE8C694FFD6A356FFD7A457FFDCAC64FFCFB5
                8DF6B98442FF0000000000000000000000000000000000000000000000000000
                00000000000000000000B78241FFE6C89AFFD19C4DFFD19D4EFFD6A65FFFD2B9
                95F6B98442FF0000000000000000000000000000000000000000000000000000
                00000000000000000000B78240FFE7CBA3FFCA9343FFCA9444FFDCC49FFBB881
                40FF000000000000000000000000000000000000000000000000000000000000
                00000000000000000000B7813FFFE6CEA9FFC28A36FFE3CEAAFFB78140FF0000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000B8813FFFE7D3B2FFE5CEABFFB7813FFF000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000B88241FFEBDDC3FFB7803DFF00000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000000000000000825D30B2B98442FF0000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000}
              ParentShowHint = False
              ShowHint = False
              SpeedButtonOptions.GroupIndex = 1
              TabOrder = 2
              OnClick = cxButtonNextClick
            end
            object cxButtonLast: TcxButton
              Left = 103
              Top = 0
              Width = 21
              Height = 21
              Enabled = False
              LookAndFeel.Kind = lfOffice11
              OptionsImage.Glyph.Data = {
                36040000424D3604000000000000360000002800000010000000100000000100
                2000000000000004000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000300000003300000000000000000000000000000000000000000000
                0000000000300000003300000033000000300000000000000000000000000000
                0000AF7D42F3B88444FF00000033000000000000000000000000000000000000
                0000AE7C41F2B78343FFB78344FFAE7C41F20000000000000000000000000000
                0000B88343FFFCCD87FFB68141FF000000330000000000000000000000000000
                0000B78243FFFBCE88FFFBCA80FFB78343FF0000000000000000000000000000
                0000B68242FFF1C684FFF3CB8BFFB68140FF0000003300000000000000000000
                0000B68141FFF4CA8AFFF2C177FFB68242FF0000000000000000000000000000
                0000B68241FFECC488FFE4B265FFE6C38CFFB68141FF00000033000000000000
                0000B68141FFF2CB90FFEDBC71FFB68242FF0000000000000000000000000000
                0000B78241FFEAC58EFFDDAA5EFFDFAB5FFFE6C493FFB78140FF000000330000
                0000B68141FFF0CC95FFE8B66AFFB68243FF0000000000000000000000000000
                0000B78241FFE8C694FFD6A356FFD7A457FFDCAC64FFCFB58DF6B98442FF0000
                0000B68140FFEFCE9DFFE5B164FFB78243FF0000000000000000000000000000
                0000B78241FFE6C89AFFD19C4DFFD19D4EFFD6A65FFFD2B995F6B98442FF0000
                0000B6813FFFEED1A4FFE0AC5DFFB78344FF0000000000000000000000000000
                0000B78240FFE7CBA3FFCA9343FFCA9444FFDCC49FFBB88140FF000000000000
                0000B6813FFFEFD4ADFFDBA556FFB88344FF0000000000000000000000000000
                0000B7813FFFE6CEA9FFC28A36FFE3CEAAFFB78140FF00000000000000000000
                0000B6803FFFEFDAB6FFD6A050FFB88344FF0000000000000000000000000000
                0000B8813FFFE7D3B2FFE5CEABFFB7813FFF0000000000000000000000000000
                0000B6803EFFF1DDC0FFD19846FFB88342FF0000000000000000000000000000
                0000B88241FFEBDDC3FFB7803DFF000000000000000000000000000000000000
                0000B8823FFFF4E5CCFFF4E6CEFFB88241FF0000000000000000000000000000
                0000825D30B2B98442FF00000000000000000000000000000000000000000000
                0000805C2FB0B88240FFB88240FF805C2FB00000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000000000000000
                0000000000000000000000000000000000000000000000000000}
              ParentShowHint = False
              ShowHint = False
              SpeedButtonOptions.GroupIndex = 1
              TabOrder = 3
              OnClick = cxButtonLastClick
            end
          end
          object cxButton4: TcxButton
            Left = 66
            Top = -1
            Width = 24
            Height = 23
            Hint = 
              'Delete Publication ID to allow new upload. Caution: Need for thi' +
              's is rare.'
            LookAndFeel.Kind = lfFlat
            OptionsImage.ImageIndex = 4
            OptionsImage.Images = cxImageList1
            ParentShowHint = False
            ShowHint = True
            TabOrder = 2
            Visible = False
            OnClick = cxButton4Click
          end
        end
        object Panel1: TPanel
          Left = 0
          Top = 21
          Width = 124
          Height = 35
          BevelOuter = bvNone
          BorderWidth = 1
          Color = 15984090
          ParentBackground = False
          TabOrder = 30
        end
        object Panel2: TPanel
          Left = 124
          Top = 21
          Width = 263
          Height = 35
          Anchors = [akLeft, akTop, akRight]
          BevelOuter = bvNone
          Color = 15984090
          ParentBackground = False
          TabOrder = 0
          object cxGroupBox1: TcxGroupBox
            Left = 0
            Top = 0
            Align = alLeft
            Anchors = [akLeft, akTop, akRight]
            ParentBackground = False
            ParentColor = False
            Style.BorderColor = clNavy
            Style.BorderStyle = ebsSingle
            Style.Color = 15984090
            TabOrder = 0
            Height = 35
            Width = 260
            object RadioButton1: TRadioButton
              Left = 7
              Top = 12
              Width = 123
              Height = 17
              Caption = 'Authored Book'
              Checked = True
              Ctl3D = True
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clNavy
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentCtl3D = False
              ParentFont = False
              TabOrder = 0
              TabStop = True
              OnClick = RadioButton1Click
            end
            object RadioButton2: TRadioButton
              AlignWithMargins = True
              Left = 136
              Top = 12
              Width = 105
              Height = 17
              Caption = 'Edited Book'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clNavy
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              TabStop = True
              OnClick = RadioButton2Click
            end
          end
        end
        object Panel3: TPanel
          Left = 0
          Top = 56
          Width = 124
          Height = 35
          BevelOuter = bvNone
          Color = 15984090
          ParentBackground = False
          TabOrder = 31
        end
        object Panel4: TPanel
          Left = 124
          Top = 56
          Width = 263
          Height = 35
          Anchors = [akLeft, akTop, akRight]
          BevelOuter = bvNone
          Color = 15984090
          ParentBackground = False
          TabOrder = 1
          object cxGroupBox2: TcxGroupBox
            Left = 0
            Top = 0
            Align = alLeft
            Anchors = [akLeft, akTop, akRight]
            ParentBackground = False
            ParentColor = False
            Style.BorderColor = clNavy
            Style.BorderStyle = ebsSingle
            Style.Color = 15984090
            TabOrder = 0
            Height = 35
            Width = 260
            object RadioButton3: TRadioButton
              Left = 7
              Top = 12
              Width = 97
              Height = 17
              Caption = 'Doctoral'
              Checked = True
              Ctl3D = True
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clNavy
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentCtl3D = False
              ParentFont = False
              TabOrder = 0
              TabStop = True
              OnClick = RadioButton3Click
            end
            object RadioButton4: TRadioButton
              AlignWithMargins = True
              Left = 84
              Top = 12
              Width = 73
              Height = 17
              Caption = 'Master'#39's'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clNavy
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              TabStop = True
              OnClick = RadioButton4Click
            end
            object RadioButton5: TRadioButton
              AlignWithMargins = True
              Left = 160
              Top = 12
              Width = 97
              Height = 17
              Caption = 'Undergraduate'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clNavy
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 2
              TabStop = True
              OnClick = RadioButton5Click
            end
          end
        end
        object LabelAuthors: TLabel
          Left = 0
          Top = 91
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Authors: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object PanelAuthors: TPanel
          Left = 124
          Top = 91
          Width = 260
          Height = 87
          Anchors = [akLeft, akTop, akRight]
          BevelOuter = bvLowered
          ShowCaption = False
          TabOrder = 2
          object AuthorsGrid: TAdvStringGrid
            Left = 1
            Top = 1
            Width = 258
            Height = 85
            Cursor = crIBeam
            Hint = 'Use ~ for non-breaking space'
            Align = alClient
            ColCount = 1
            Ctl3D = True
            DefaultRowHeight = 20
            DoubleBuffered = True
            DrawingStyle = gdsClassic
            FixedCols = 0
            RowCount = 4
            FixedRows = 0
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
            ParentCtl3D = False
            ParentDoubleBuffered = False
            ParentFont = False
            ParentShowHint = False
            ScrollBars = ssVertical
            ShowHint = True
            TabOrder = 0
            OnExit = AuthorsGridExit
            HoverRowCells = [hcNormal, hcSelected]
            HintShowLargeTextPos = hpCursor
            ActiveCellFont.Charset = DEFAULT_CHARSET
            ActiveCellFont.Color = clWindowText
            ActiveCellFont.Height = -11
            ActiveCellFont.Name = 'Tahoma'
            ActiveCellFont.Style = [fsBold]
            ActiveCellColor = 15387318
            ColumnSize.Stretch = True
            ColumnSize.StretchColumn = 0
            ColumnSize.SynchWithGrid = True
            ControlLook.FixedGradientFrom = clWhite
            ControlLook.FixedGradientTo = clSilver
            ControlLook.FixedGradientHoverFrom = 13619409
            ControlLook.FixedGradientHoverTo = 12502728
            ControlLook.FixedGradientHoverMirrorFrom = 12502728
            ControlLook.FixedGradientHoverMirrorTo = 11254975
            ControlLook.FixedGradientDownFrom = 8816520
            ControlLook.FixedGradientDownTo = 7568510
            ControlLook.FixedGradientDownMirrorFrom = 7568510
            ControlLook.FixedGradientDownMirrorTo = 6452086
            ControlLook.FixedGradientDownBorder = 14007466
            ControlLook.CheckSize = 16
            ControlLook.ControlStyle = csTMS
            ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
            ControlLook.DropDownHeader.Font.Color = clWindowText
            ControlLook.DropDownHeader.Font.Height = -11
            ControlLook.DropDownHeader.Font.Name = 'Tahoma'
            ControlLook.DropDownHeader.Font.Style = []
            ControlLook.DropDownHeader.Visible = True
            ControlLook.DropDownHeader.Buttons = <>
            ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
            ControlLook.DropDownFooter.Font.Color = clWindowText
            ControlLook.DropDownFooter.Font.Height = -11
            ControlLook.DropDownFooter.Font.Name = 'Tahoma'
            ControlLook.DropDownFooter.Font.Style = []
            ControlLook.DropDownFooter.Visible = True
            ControlLook.DropDownFooter.Buttons = <>
            EnableHTML = False
            Filter = <>
            FilterDropDown.Font.Charset = DEFAULT_CHARSET
            FilterDropDown.Font.Color = clWindowText
            FilterDropDown.Font.Height = -11
            FilterDropDown.Font.Name = 'Tahoma'
            FilterDropDown.Font.Style = []
            FilterDropDownClear = '(All)'
            FilterEdit.TypeNames.Strings = (
              'Starts with'
              'Ends with'
              'Contains'
              'Not contains'
              'Equal'
              'Not equal'
              'Clear')
            FixedColWidth = 254
            FixedRowHeight = 20
            FixedFont.Charset = DEFAULT_CHARSET
            FixedFont.Color = clWindowText
            FixedFont.Height = -11
            FixedFont.Name = 'Tahoma'
            FixedFont.Style = [fsBold]
            FloatFormat = '%.2f'
            FocusHelper.Enabled = True
            HoverButtons.Buttons = <>
            HoverButtons.Position = hbLeftFromColumnLeft
            HTMLSettings.ImageFolder = 'images'
            HTMLSettings.ImageBaseName = 'img'
            Look = glTMS
            MouseActions.AutoSizeColOnDblClick = False
            Navigation.AllowDeleteRow = True
            Navigation.AlwaysEdit = True
            Navigation.AdvanceOnEnter = True
            Navigation.AdvanceOnEnterLoop = False
            Navigation.AdvanceInsert = True
            Navigation.AllowCtrlEnter = False
            Navigation.AllowClipboardColGrow = False
            Navigation.AppendOnArrowDown = True
            PrintSettings.DateFormat = 'dd/mm/yyyy'
            PrintSettings.Font.Charset = DEFAULT_CHARSET
            PrintSettings.Font.Color = clWindowText
            PrintSettings.Font.Height = -11
            PrintSettings.Font.Name = 'Tahoma'
            PrintSettings.Font.Style = []
            PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
            PrintSettings.FixedFont.Color = clWindowText
            PrintSettings.FixedFont.Height = -11
            PrintSettings.FixedFont.Name = 'Tahoma'
            PrintSettings.FixedFont.Style = []
            PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
            PrintSettings.HeaderFont.Color = clWindowText
            PrintSettings.HeaderFont.Height = -11
            PrintSettings.HeaderFont.Name = 'Tahoma'
            PrintSettings.HeaderFont.Style = []
            PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
            PrintSettings.FooterFont.Color = clWindowText
            PrintSettings.FooterFont.Height = -11
            PrintSettings.FooterFont.Name = 'Tahoma'
            PrintSettings.FooterFont.Style = []
            PrintSettings.PageNumSep = '/'
            SearchFooter.ColorTo = 15790320
            SearchFooter.FindNextCaption = 'Find &next'
            SearchFooter.FindPrevCaption = 'Find &previous'
            SearchFooter.Font.Charset = DEFAULT_CHARSET
            SearchFooter.Font.Color = clWindowText
            SearchFooter.Font.Height = -11
            SearchFooter.Font.Name = 'Tahoma'
            SearchFooter.Font.Style = []
            SearchFooter.HighLightCaption = 'Highlight'
            SearchFooter.HintClose = 'Close'
            SearchFooter.HintFindNext = 'Find next occurrence'
            SearchFooter.HintFindPrev = 'Find previous occurrence'
            SearchFooter.HintHighlight = 'Highlight occurrences'
            SearchFooter.MatchCaseCaption = 'Match case'
            SearchFooter.ResultFormat = '(%d of %d)'
            SortSettings.DefaultFormat = ssAutomatic
            SortSettings.HeaderColorTo = 16579058
            SortSettings.HeaderMirrorColor = 16380385
            SortSettings.HeaderMirrorColorTo = 16182488
            Version = '8.3.5.4'
            WordWrap = False
            ExplicitHeight = 80
            ColWidths = (
              254)
          end
        end
        object LabelThesisAuthor: TLabel
          Left = 0
          Top = 178
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Author: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxThesisAuthorEdit: TcxTextEdit
          Left = 124
          Top = 178
          Anchors = [akLeft, akTop, akRight]
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 3
          OnExit = cxThesisAuthorEditExit
          Width = 260
        end
        object LabelYear: TLabel
          Left = 0
          Top = 199
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Year: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxYearEdit: TcxTextEdit
          Left = 124
          Top = 199
          Anchors = [akLeft, akTop, akRight]
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 4
          OnExit = cxYearEditExit
          Width = 260
        end
        object LabelTitle: TLabel
          Left = 0
          Top = 220
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Article Title: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxTitleMemo: TcxMemo
          Left = 124
          Top = 220
          Anchors = [akLeft, akTop, akRight]
          Properties.ScrollBars = ssVertical
          Style.LookAndFeel.Kind = lfFlat
          StyleDisabled.LookAndFeel.Kind = lfFlat
          StyleFocused.LookAndFeel.Kind = lfFlat
          StyleHot.LookAndFeel.Kind = lfFlat
          TabOrder = 5
          OnExit = cxTitleMemoExit
          Height = 49
          Width = 260
        end
        object LabelJournal: TLabel
          Left = 0
          Top = 269
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Journal: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxJournalNameEdit: TcxTextEdit
          Left = 124
          Top = 269
          Anchors = [akLeft, akTop, akRight]
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 6
          OnExit = cxJournalNameEditExit
          Width = 260
        end
        object LabelJournalVolume: TLabel
          Left = 0
          Top = 290
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Volume: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxJournalVolumeEdit: TcxTextEdit
          Left = 124
          Top = 290
          Anchors = [akLeft, akTop, akRight]
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 7
          OnExit = cxJournalVolumeEditExit
          Width = 260
        end
        object LabelJournalIssue: TLabel
          Left = 0
          Top = 311
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Issue: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxJournalIssueEdit: TcxTextEdit
          Left = 124
          Top = 311
          Anchors = [akLeft, akTop, akRight]
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 8
          OnExit = cxJournalIssueEditExit
          Width = 260
        end
        object LabelPages: TLabel
          Left = 0
          Top = 332
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Pages: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxPageEdit: TcxTextEdit
          Left = 124
          Top = 332
          Anchors = [akLeft, akTop, akRight]
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 9
          OnExit = cxPageEditExit
          Width = 260
        end
        object LabelCitationNumber: TLabel
          Left = 0
          Top = 353
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Citation Number: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxCitationNumber: TcxTextEdit
          Left = 124
          Top = 353
          Anchors = [akLeft, akTop, akRight]
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 10
          OnExit = cxCitationNumberExit
          Width = 260
        end
        object LabelURL: TLabel
          Left = 0
          Top = 374
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'URL: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxURLEdit: TcxTextEdit
          Left = 124
          Top = 374
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 11
          OnExit = cxURLEditExit
          Width = 260
        end
        object LabelDOI: TLabel
          Left = 0
          Top = 395
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Digital Object Identifier: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxDOIEdit: TcxTextEdit
          Left = 124
          Top = 395
          Anchors = [akLeft, akTop, akRight]
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 12
          OnExit = cxDOIEditExit
          Width = 260
        end
        object LabelEditors: TLabel
          Left = 0
          Top = 416
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Editors: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object PanelEditors: TPanel
          Left = 124
          Top = 416
          Width = 260
          Height = 87
          Anchors = [akLeft, akTop, akRight]
          BevelOuter = bvLowered
          TabOrder = 13
          object EditorsGrid: TAdvStringGrid
            Left = 1
            Top = 1
            Width = 258
            Height = 85
            Cursor = crDefault
            Align = alClient
            ColCount = 1
            Ctl3D = True
            DefaultRowHeight = 20
            DrawingStyle = gdsClassic
            FixedCols = 0
            RowCount = 5
            FixedRows = 0
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
            ParentCtl3D = False
            ParentFont = False
            ScrollBars = ssVertical
            TabOrder = 0
            OnExit = EditorsGridExit
            HoverRowCells = [hcNormal, hcSelected]
            ActiveCellFont.Charset = DEFAULT_CHARSET
            ActiveCellFont.Color = clWindowText
            ActiveCellFont.Height = -11
            ActiveCellFont.Name = 'Tahoma'
            ActiveCellFont.Style = [fsBold]
            ActiveCellColor = 15387318
            ColumnSize.Stretch = True
            ColumnSize.StretchColumn = 0
            ColumnSize.SynchWithGrid = True
            ControlLook.FixedGradientFrom = clWhite
            ControlLook.FixedGradientTo = clSilver
            ControlLook.FixedGradientHoverFrom = 13619409
            ControlLook.FixedGradientHoverTo = 12502728
            ControlLook.FixedGradientHoverMirrorFrom = 12502728
            ControlLook.FixedGradientHoverMirrorTo = 11254975
            ControlLook.FixedGradientDownFrom = 8816520
            ControlLook.FixedGradientDownTo = 7568510
            ControlLook.FixedGradientDownMirrorFrom = 7568510
            ControlLook.FixedGradientDownMirrorTo = 6452086
            ControlLook.FixedGradientDownBorder = 14007466
            ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
            ControlLook.DropDownHeader.Font.Color = clWindowText
            ControlLook.DropDownHeader.Font.Height = -11
            ControlLook.DropDownHeader.Font.Name = 'Tahoma'
            ControlLook.DropDownHeader.Font.Style = []
            ControlLook.DropDownHeader.Visible = True
            ControlLook.DropDownHeader.Buttons = <>
            ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
            ControlLook.DropDownFooter.Font.Color = clWindowText
            ControlLook.DropDownFooter.Font.Height = -11
            ControlLook.DropDownFooter.Font.Name = 'Tahoma'
            ControlLook.DropDownFooter.Font.Style = []
            ControlLook.DropDownFooter.Visible = True
            ControlLook.DropDownFooter.Buttons = <>
            Filter = <>
            FilterDropDown.Font.Charset = DEFAULT_CHARSET
            FilterDropDown.Font.Color = clWindowText
            FilterDropDown.Font.Height = -11
            FilterDropDown.Font.Name = 'Tahoma'
            FilterDropDown.Font.Style = []
            FilterDropDownClear = '(All)'
            FilterEdit.TypeNames.Strings = (
              'Starts with'
              'Ends with'
              'Contains'
              'Not contains'
              'Equal'
              'Not equal'
              'Clear')
            FixedColWidth = 237
            FixedRowHeight = 20
            FixedFont.Charset = DEFAULT_CHARSET
            FixedFont.Color = clWindowText
            FixedFont.Height = -11
            FixedFont.Name = 'Tahoma'
            FixedFont.Style = [fsBold]
            FloatFormat = '%.2f'
            HoverButtons.Buttons = <>
            HoverButtons.Position = hbLeftFromColumnLeft
            HTMLSettings.ImageFolder = 'images'
            HTMLSettings.ImageBaseName = 'img'
            Look = glTMS
            Navigation.AllowInsertRow = True
            Navigation.AllowDeleteRow = True
            Navigation.AdvanceOnEnter = True
            Navigation.AdvanceOnEnterLoop = False
            Navigation.AdvanceInsert = True
            Navigation.AllowCtrlEnter = False
            Navigation.AllowClipboardColGrow = False
            Navigation.AppendOnArrowDown = True
            PrintSettings.DateFormat = 'dd/mm/yyyy'
            PrintSettings.Font.Charset = DEFAULT_CHARSET
            PrintSettings.Font.Color = clWindowText
            PrintSettings.Font.Height = -11
            PrintSettings.Font.Name = 'Tahoma'
            PrintSettings.Font.Style = []
            PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
            PrintSettings.FixedFont.Color = clWindowText
            PrintSettings.FixedFont.Height = -11
            PrintSettings.FixedFont.Name = 'Tahoma'
            PrintSettings.FixedFont.Style = []
            PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
            PrintSettings.HeaderFont.Color = clWindowText
            PrintSettings.HeaderFont.Height = -11
            PrintSettings.HeaderFont.Name = 'Tahoma'
            PrintSettings.HeaderFont.Style = []
            PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
            PrintSettings.FooterFont.Color = clWindowText
            PrintSettings.FooterFont.Height = -11
            PrintSettings.FooterFont.Name = 'Tahoma'
            PrintSettings.FooterFont.Style = []
            PrintSettings.PageNumSep = '/'
            SearchFooter.ColorTo = 15790320
            SearchFooter.FindNextCaption = 'Find &next'
            SearchFooter.FindPrevCaption = 'Find &previous'
            SearchFooter.Font.Charset = DEFAULT_CHARSET
            SearchFooter.Font.Color = clWindowText
            SearchFooter.Font.Height = -11
            SearchFooter.Font.Name = 'Tahoma'
            SearchFooter.Font.Style = []
            SearchFooter.HighLightCaption = 'Highlight'
            SearchFooter.HintClose = 'Close'
            SearchFooter.HintFindNext = 'Find next occurrence'
            SearchFooter.HintFindPrev = 'Find previous occurrence'
            SearchFooter.HintHighlight = 'Highlight occurrences'
            SearchFooter.MatchCaseCaption = 'Match case'
            SearchFooter.ResultFormat = '(%d of %d)'
            SortSettings.DefaultFormat = ssAutomatic
            SortSettings.HeaderColorTo = 16579058
            SortSettings.HeaderMirrorColor = 16380385
            SortSettings.HeaderMirrorColorTo = 16182488
            Version = '8.3.5.4'
            ExplicitHeight = 77
            ColWidths = (
              237)
          end
        end
        object LabelBookTitle: TLabel
          Left = 0
          Top = 503
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Book Title: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxBookTitleMemo: TcxMemo
          Left = 124
          Top = 503
          Anchors = [akLeft, akTop, akRight]
          Properties.ScrollBars = ssVertical
          Style.LookAndFeel.Kind = lfFlat
          StyleDisabled.LookAndFeel.Kind = lfFlat
          StyleFocused.LookAndFeel.Kind = lfFlat
          StyleHot.LookAndFeel.Kind = lfFlat
          TabOrder = 14
          OnExit = cxBookTitleMemoExit
          Height = 49
          Width = 260
        end
        object LabelEdition: TLabel
          Left = 0
          Top = 552
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Edition: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxEditionEdit: TcxTextEdit
          Left = 124
          Top = 552
          Anchors = [akLeft, akTop, akRight]
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 15
          OnExit = cxEditionEditExit
          Width = 260
        end
        object LabelNumVols: TLabel
          Left = 0
          Top = 573
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Number of Volumes: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxNumVolsEdit: TcxTextEdit
          Left = 124
          Top = 573
          Anchors = [akLeft, akTop, akRight]
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 16
          OnExit = cxNumVolsEditExit
          Width = 260
        end
        object LabelVolumeNumber: TLabel
          Left = 0
          Top = 594
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Volume Number: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxVolumeNumberEdit: TcxTextEdit
          Left = 124
          Top = 594
          Anchors = [akLeft, akTop, akRight]
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 17
          OnExit = cxVolumeNumberEditExit
          Width = 260
        end
        object LabelVolumeTitle: TLabel
          Left = 0
          Top = 615
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Volume Title: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxVolumeTitleMemo: TcxMemo
          Left = 124
          Top = 615
          Anchors = [akLeft, akTop, akRight]
          Properties.ScrollBars = ssVertical
          Style.LookAndFeel.Kind = lfFlat
          StyleDisabled.LookAndFeel.Kind = lfFlat
          StyleFocused.LookAndFeel.Kind = lfFlat
          StyleHot.LookAndFeel.Kind = lfFlat
          TabOrder = 18
          OnExit = cxVolumeTitleMemoExit
          Height = 49
          Width = 260
        end
        object LabelSeriesTitle: TLabel
          Left = 0
          Top = 664
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Series Title: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxSeriesTitleMemo: TcxMemo
          Left = 124
          Top = 664
          Anchors = [akLeft, akTop, akRight]
          Properties.ScrollBars = ssVertical
          Style.LookAndFeel.Kind = lfFlat
          StyleDisabled.LookAndFeel.Kind = lfFlat
          StyleFocused.LookAndFeel.Kind = lfFlat
          StyleHot.LookAndFeel.Kind = lfFlat
          TabOrder = 19
          OnExit = cxSeriesTitleMemoExit
          Height = 49
          Width = 260
        end
        object LabelSeriesVolumeNumber: TLabel
          Left = 0
          Top = 713
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Series Volume Number: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxSeriesVolumeEdit: TcxTextEdit
          Left = 124
          Top = 713
          Anchors = [akLeft, akTop, akRight]
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 20
          OnExit = cxSeriesVolumeEditExit
          Width = 260
        end
        object LabelPublisher: TLabel
          Left = 0
          Top = 734
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Publisher: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxPublisherEdit: TcxTextEdit
          Left = 124
          Top = 734
          Anchors = [akLeft, akTop, akRight]
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 21
          OnExit = cxPublisherEditExit
          Width = 260
        end
        object LabelUniversity: TLabel
          Left = 0
          Top = 755
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'University: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxUniversityEdit: TcxTextEdit
          Left = 124
          Top = 755
          Anchors = [akLeft, akTop, akRight]
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 22
          OnExit = cxUniversityEditExit
          Width = 260
        end
        object LabelCity: TLabel
          Left = 0
          Top = 776
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'City: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxCityEdit: TcxTextEdit
          Left = 124
          Top = 776
          Anchors = [akLeft, akTop, akRight]
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 23
          OnExit = cxCityEditExit
          Width = 260
        end
        object LabelState: TLabel
          Left = 0
          Top = 797
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'State/Province: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxStateEdit: TcxTextEdit
          Left = 124
          Top = 797
          Anchors = [akLeft, akTop, akRight]
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 24
          OnExit = cxStateEditExit
          Width = 260
        end
        object LabelCountry: TLabel
          Left = 0
          Top = 818
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Country: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxCountryEdit: TcxTextEdit
          Left = 124
          Top = 818
          Anchors = [akLeft, akTop, akRight]
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 25
          OnExit = cxCountryEditExit
          Width = 260
        end
        object LabelTranslator: TLabel
          Left = 0
          Top = 839
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Translator: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object PanelTranslator: TPanel
          Left = 124
          Top = 839
          Width = 260
          Height = 67
          Anchors = [akLeft, akTop, akRight]
          BevelOuter = bvLowered
          TabOrder = 26
          object TranslatorGrid: TAdvStringGrid
            Left = 1
            Top = 1
            Width = 258
            Height = 65
            Cursor = crDefault
            Align = alClient
            ColCount = 1
            Ctl3D = True
            DefaultRowHeight = 20
            DrawingStyle = gdsClassic
            FixedCols = 0
            RowCount = 5
            FixedRows = 0
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
            ParentCtl3D = False
            ParentFont = False
            ScrollBars = ssVertical
            TabOrder = 0
            OnExit = TranslatorGridExit
            HoverRowCells = [hcNormal, hcSelected]
            ActiveCellFont.Charset = DEFAULT_CHARSET
            ActiveCellFont.Color = clWindowText
            ActiveCellFont.Height = -11
            ActiveCellFont.Name = 'Tahoma'
            ActiveCellFont.Style = [fsBold]
            ActiveCellColor = 15387318
            ColumnSize.Stretch = True
            ColumnSize.StretchColumn = 0
            ColumnSize.SynchWithGrid = True
            ControlLook.FixedGradientFrom = clWhite
            ControlLook.FixedGradientTo = clSilver
            ControlLook.FixedGradientHoverFrom = 13619409
            ControlLook.FixedGradientHoverTo = 12502728
            ControlLook.FixedGradientHoverMirrorFrom = 12502728
            ControlLook.FixedGradientHoverMirrorTo = 11254975
            ControlLook.FixedGradientDownFrom = 8816520
            ControlLook.FixedGradientDownTo = 7568510
            ControlLook.FixedGradientDownMirrorFrom = 7568510
            ControlLook.FixedGradientDownMirrorTo = 6452086
            ControlLook.FixedGradientDownBorder = 14007466
            ControlLook.DropDownHeader.Font.Charset = DEFAULT_CHARSET
            ControlLook.DropDownHeader.Font.Color = clWindowText
            ControlLook.DropDownHeader.Font.Height = -11
            ControlLook.DropDownHeader.Font.Name = 'Tahoma'
            ControlLook.DropDownHeader.Font.Style = []
            ControlLook.DropDownHeader.Visible = True
            ControlLook.DropDownHeader.Buttons = <>
            ControlLook.DropDownFooter.Font.Charset = DEFAULT_CHARSET
            ControlLook.DropDownFooter.Font.Color = clWindowText
            ControlLook.DropDownFooter.Font.Height = -11
            ControlLook.DropDownFooter.Font.Name = 'Tahoma'
            ControlLook.DropDownFooter.Font.Style = []
            ControlLook.DropDownFooter.Visible = True
            ControlLook.DropDownFooter.Buttons = <>
            Filter = <>
            FilterDropDown.Font.Charset = DEFAULT_CHARSET
            FilterDropDown.Font.Color = clWindowText
            FilterDropDown.Font.Height = -11
            FilterDropDown.Font.Name = 'Tahoma'
            FilterDropDown.Font.Style = []
            FilterDropDownClear = '(All)'
            FilterEdit.TypeNames.Strings = (
              'Starts with'
              'Ends with'
              'Contains'
              'Not contains'
              'Equal'
              'Not equal'
              'Clear')
            FixedColWidth = 237
            FixedRowHeight = 20
            FixedFont.Charset = DEFAULT_CHARSET
            FixedFont.Color = clWindowText
            FixedFont.Height = -11
            FixedFont.Name = 'Tahoma'
            FixedFont.Style = [fsBold]
            FloatFormat = '%.2f'
            HoverButtons.Buttons = <>
            HoverButtons.Position = hbLeftFromColumnLeft
            HTMLSettings.ImageFolder = 'images'
            HTMLSettings.ImageBaseName = 'img'
            Look = glTMS
            Navigation.AllowInsertRow = True
            Navigation.AllowDeleteRow = True
            Navigation.AdvanceOnEnter = True
            Navigation.AdvanceOnEnterLoop = False
            Navigation.AdvanceInsert = True
            Navigation.AllowCtrlEnter = False
            Navigation.AllowClipboardColGrow = False
            Navigation.AppendOnArrowDown = True
            PrintSettings.DateFormat = 'dd/mm/yyyy'
            PrintSettings.Font.Charset = DEFAULT_CHARSET
            PrintSettings.Font.Color = clWindowText
            PrintSettings.Font.Height = -11
            PrintSettings.Font.Name = 'Tahoma'
            PrintSettings.Font.Style = []
            PrintSettings.FixedFont.Charset = DEFAULT_CHARSET
            PrintSettings.FixedFont.Color = clWindowText
            PrintSettings.FixedFont.Height = -11
            PrintSettings.FixedFont.Name = 'Tahoma'
            PrintSettings.FixedFont.Style = []
            PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
            PrintSettings.HeaderFont.Color = clWindowText
            PrintSettings.HeaderFont.Height = -11
            PrintSettings.HeaderFont.Name = 'Tahoma'
            PrintSettings.HeaderFont.Style = []
            PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
            PrintSettings.FooterFont.Color = clWindowText
            PrintSettings.FooterFont.Height = -11
            PrintSettings.FooterFont.Name = 'Tahoma'
            PrintSettings.FooterFont.Style = []
            PrintSettings.PageNumSep = '/'
            SearchFooter.ColorTo = 15790320
            SearchFooter.FindNextCaption = 'Find &next'
            SearchFooter.FindPrevCaption = 'Find &previous'
            SearchFooter.Font.Charset = DEFAULT_CHARSET
            SearchFooter.Font.Color = clWindowText
            SearchFooter.Font.Height = -11
            SearchFooter.Font.Name = 'Tahoma'
            SearchFooter.Font.Style = []
            SearchFooter.HighLightCaption = 'Highlight'
            SearchFooter.HintClose = 'Close'
            SearchFooter.HintFindNext = 'Find next occurrence'
            SearchFooter.HintFindPrev = 'Find previous occurrence'
            SearchFooter.HintHighlight = 'Highlight occurrences'
            SearchFooter.MatchCaseCaption = 'Match case'
            SearchFooter.ResultFormat = '(%d of %d)'
            SortSettings.DefaultFormat = ssAutomatic
            SortSettings.HeaderColorTo = 16579058
            SortSettings.HeaderMirrorColor = 16380385
            SortSettings.HeaderMirrorColorTo = 16182488
            Version = '8.3.5.4'
            ColWidths = (
              237)
          end
        end
        object LabelOrigLang: TLabel
          Left = 0
          Top = 906
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Original Language: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxOrigLangEdit: TcxTextEdit
          Left = 124
          Top = 906
          Anchors = [akLeft, akTop, akRight]
          ParentShowHint = False
          ShowHint = True
          Style.BorderStyle = ebsFlat
          Style.LookAndFeel.Kind = lfOffice11
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 27
          OnExit = cxOrigLangEditExit
          Width = 260
        end
        object NotesLabel: TLabel
          Left = 0
          Top = 927
          Width = 124
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Notes: '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object cxNotesMemo: TcxMemo
          Left = 124
          Top = 927
          Anchors = [akLeft, akTop, akRight]
          Properties.ScrollBars = ssVertical
          Style.LookAndFeel.Kind = lfFlat
          StyleDisabled.LookAndFeel.Kind = lfFlat
          StyleFocused.LookAndFeel.Kind = lfFlat
          StyleHot.LookAndFeel.Kind = lfFlat
          TabOrder = 28
          OnExit = cxNotesMemoExit
          Height = 49
          Width = 260
        end
        object Panel5: TPanel
          Left = 0
          Top = 976
          Width = 387
          Height = 193
          Anchors = [akLeft, akTop, akRight]
          BevelOuter = bvNone
          Color = 15984090
          ParentBackground = False
          TabOrder = 29
          object Splitter1: TSplitter
            Left = 0
            Top = 30
            Width = 387
            Height = 3
            Cursor = crVSplit
            Align = alTop
            Beveled = True
            MinSize = 20
            ResizeStyle = rsUpdate
            OnCanResize = Splitter1CanResize
            ExplicitLeft = 14
            ExplicitTop = 90
          end
          object Panel6: TPanel
            Left = 0
            Top = 0
            Width = 387
            Height = 30
            Align = alTop
            BevelOuter = bvNone
            Color = 15984090
            ParentBackground = False
            TabOrder = 2
            object Panel8: TPanel
              Left = 0
              Top = 0
              Width = 124
              Height = 30
              Align = alLeft
              BevelOuter = bvNone
              Color = 15984090
              ParentBackground = False
              TabOrder = 1
              object LabelUnparsedCitation: TLabel
                Left = 0
                Top = 0
                Width = 124
                Height = 13
                Alignment = taRightJustify
                AutoSize = False
                Caption = 'Work Space: '
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clNavy
                Font.Height = -11
                Font.Name = 'Tahoma'
                Font.Style = []
                ParentFont = False
              end
            end
            object cxWorkSpaceMemo: TcxMemo
              Left = 124
              Top = 0
              Align = alLeft
              Anchors = [akLeft, akTop, akRight, akBottom]
              ParentShowHint = False
              Properties.ScrollBars = ssVertical
              ShowHint = False
              Style.LookAndFeel.Kind = lfFlat
              StyleDisabled.LookAndFeel.Kind = lfFlat
              StyleFocused.LookAndFeel.Kind = lfFlat
              StyleHot.LookAndFeel.Kind = lfFlat
              TabOrder = 0
              Height = 30
              Width = 260
            end
          end
          object Panel9: TPanel
            Left = 0
            Top = 33
            Width = 124
            Height = 160
            Align = alLeft
            BevelOuter = bvNone
            Color = 15984090
            ParentBackground = False
            TabOrder = 0
            object cxButton2: TcxButton
              Left = 8
              Top = 4
              Width = 110
              Height = 25
              Caption = 'Format Citation'
              LookAndFeel.Kind = lfOffice11
              TabOrder = 0
              OnClick = cxButton2Click
            end
          end
          object cxCitationMemo: TcxMemo
            Left = 124
            Top = 33
            Align = alLeft
            Anchors = [akLeft, akTop, akRight, akBottom]
            Properties.ScrollBars = ssVertical
            Style.LookAndFeel.Kind = lfFlat
            StyleDisabled.LookAndFeel.Kind = lfFlat
            StyleFocused.LookAndFeel.Kind = lfFlat
            StyleHot.LookAndFeel.Kind = lfFlat
            TabOrder = 1
            Height = 160
            Width = 260
          end
        end
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 458
    Width = 410
    Height = 19
    Color = 15984090
    Panels = <>
  end
  object Panel7: TPanel
    Left = 0
    Top = 410
    Width = 410
    Height = 48
    Align = alBottom
    BevelOuter = bvLowered
    Color = 15984090
    ParentBackground = False
    TabOrder = 1
    object FlowPanel1: TFlowPanel
      Left = 140
      Top = 12
      Width = 216
      Height = 25
      AutoSize = True
      AutoWrap = False
      BevelOuter = bvNone
      Color = 15984090
      Ctl3D = False
      ParentBackground = False
      ParentCtl3D = False
      TabOrder = 0
      object cxButton9: TcxButton
        Left = 0
        Top = 0
        Width = 72
        Height = 25
        Caption = 'Ok'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 1
        OptionsImage.ImageIndex = 1
        OptionsImage.Images = cxImageList1
        TabOrder = 0
        OnClick = cxButton9Click
      end
      object cxButton1: TcxButton
        Left = 72
        Top = 0
        Width = 72
        Height = 25
        Caption = 'Cancel'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 2
        OptionsImage.ImageIndex = 2
        OptionsImage.Images = cxImageList1
        TabOrder = 1
      end
      object cxButton3: TcxButton
        Left = 144
        Top = 0
        Width = 72
        Height = 25
        Caption = 'Upload'
        Enabled = False
        LookAndFeel.Kind = lfOffice11
        OptionsImage.ImageIndex = 3
        OptionsImage.Images = cxImageList1
        TabOrder = 2
        Visible = False
        OnClick = cxButton3Click
      end
    end
  end
  object cxImageList1: TcxImageList
    FormatVersion = 1
    DesignInfo = 27263000
    ImageInfo = <
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFD5D5D5FFE4E4E4FFFFFFFFFFFFFFFFFFC2C3C4FFBBBE
          C0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD1D1D1FFB1B1B1FFF7F6
          F6FFFFFFFFFFE2E2E2FF969696FF909090FFD1D1D1FFFFFFFFFFC8CACCFF727D
          83FFDFE0E1FFFFFFFFFFFFFFFFFFFFFFFFFFDADADAFFC7C8C8FF696A6AFF8B8F
          93FFF2F3F4FFFFFFFFFFAAAAAAFF6A6A6AFF7E7D7DFFD8D8D8FFFFFFFFFFCDD1
          D2FF8A9497FFC8CBCCFFE6E5E5FFAAAAAAFF696C6DFF828789FF7B8588FF6571
          7BFF9BA0A6FFF9F9F9FFFFFFFFFF858585FF525758FF838587FFFFFFFFFFFFFF
          FFFFC8CBCDFF888F92FF8A8F94FF85898CFF818485FF3F4446FF67757AFF8B93
          96FF939493FFCACACAFFFFFFFFFFD7D8D8FF646D71FF596265FFFFFFFFFFFFFF
          FFFFE3E4E4FF758289FF627487FF6E7E91FF7F888EFF556064FF546268FF8287
          89FFACAEB0FFCFCECEFFD8D8D8FFFFFFFFFFCCCECFFF5E696DFFFFFFFFFFFFFF
          FFFFD7DADAFF64737BFF5B718CFF4C6483FF50616BFF516268FF536166FF7B82
          85FF8E9299FFECECECFFFFFFFFFFFFFFFFFFFFFFFFFF778287FFFFFFFFFFFFFF
          FFFFA1AAAEFF53646BFF515B65FF485866FF4D6068FF465C68FF576C7DFFB4B7
          B7FFDCDCDCFFF8F8F9FFFFFFFFFFFFFFFFFFFFFFFFFFA7AFB2FFFFFFFFFFFFFF
          FFFF8A969BFF475E66FF545D61FF33444CFF445960FF4B5F6DFF586F8AFF6873
          79FF606973FFD0D3D7FFFFFFFFFFFFFFFFFFFFFFFFFFA9B1B4FFFFFFFFFFFFFF
          FFFF949B9FFF3A5059FF3B4D54FF182E37FF384C54FF535D62FF535F6BFF727F
          85FF6F7A82FF8D9499FFDDDDDEFFFFFFFFFFFFFFFFFF8E9A9EFFFFFFFFFFFFFF
          FFFFD5D5D5FF57666BFF2F4851FF18343FFF253D46FF48565CFF555F63FF7A87
          8CFF879195FF717B80FF989D9FFFFFFFFFFFA4ACAFFFB9C0C3FFFFFFFFFFFFFF
          FFFFF2F1F0FF6C797EFF324F5AFF203F4AFF233D47FF3C5059FF596B72FF7482
          88FF818C92FF818C91FF8B9498FF9EA3A6FF9CA5A8FFFFFFFFFFFFFFFFFFFFFF
          FFFFDDDDDCFF859297FF324D58FF2B4651FF29454FFF394F58FF435860FF6071
          78FF75848AFF768489FF7F888BFFB3B8BAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFD8DBDCFFB8BFC2FF7C898FFF364D56FF344B54FF395159FF4258
          61FF627177FF848D91FFDADBDBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8D979AFF43565EFF28414BFF3145
          4EFF798083FFEBEBEBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCACECFFF859297FF7880
          84FFD3D3D3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000000000000000000000A000000250000003300000033000000330000
          0033000000250000000A00000000000000000000000000000000000000000000
          00000000000000000022001D105C006738C9008C4BFF008B4AFF008B4AFF008C
          4BFF006738C9001D105C0000001E000000000000000000000000000000000000
          00000000001E005E33BB009050FF01A169FF01AB76FF01AC79FF01AC79FF01AB
          76FF01A169FF009050FF00532DAA0000001E0000000000000000000000000000
          000A00532DAA009152FF02AC77FF00C38CFF00D79BFF00DA9CFF00DA9CFF00D7
          9CFF01C38CFF01AB76FF009253FF00532DAA0000000A0000000000000000001C
          1051009051FF0FB483FF00D298FF00D598FF00D192FF00CF90FF00D091FF00D3
          96FF00D69BFF00D198FF01AB76FF009050FF001D105100000000000000000067
          36C916AB78FF10C996FF00D397FF00CD8CFFFFFFFFFFFFFFFFFFFFFFFFFF00CC
          8CFF00D195FF00D59BFF01C18CFF01A169FF006838C90000000000000000008A
          48FF39C49DFF00D198FF00CB8CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFF00CA8CFF00CF96FF00D29BFF01AB76FF008C4BFF00000000000000000089
          46FF52D2B0FF00CC92FFFFFFFFFFFFFFFFFFFFFFFFFF00C484FFFFFFFFFFFFFF
          FFFFFFFFFFFF00C88DFF00D09AFF00AD79FF008B4AFF00000000000000000088
          45FF68DDBEFF00C991FFFFFFFFFFFFFFFFFF00C68CFF00C891FF00C58BFFFFFF
          FFFFFFFFFFFFFFFFFFFF00CC96FF00AD78FF008B4AFF00000000000000000088
          46FF76E0C6FF00CB98FF00C590FF00C691FF00C895FF00C997FF00C894FF00C3
          8CFFFFFFFFFFFFFFFFFF00C792FF00AB75FF008C4BFF00000000000000000065
          34BE59C9A4FF49DEBCFF00C794FF00C897FF00C998FF00C999FF00C998FF00C7
          94FF00C38EFFFFFFFFFF00BD8AFF00A067FF006838BF0000000000000000001C
          0F330A9458FFADF8E9FF18D0A7FF00C495FF00C697FF00C698FF00C798FF00C7
          98FF00C697FF00C596FF12B585FF008F50FF001C0F3300000000000000000000
          0000005C30AA199C63FFBCFFF7FF5EE4C9FF00C59AFF00C396FF00C497FF00C5
          9AFF22CAA2FF2FC196FF029355FF00522C950000000000000000000000000000
          00000000000000512A950E9659FF74D5B6FFA0F4E1FF94EFDCFF7CE6CCFF5ED6
          B5FF2EB587FF039152FF005D33AA000000000000000000000000000000000000
          00000000000000000000001C0F33006433BB008744FF008743FF008744FF0089
          46FF006636BB001C0F3300000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000001200000033000000330000003300000033000000330000
          0033000000330000001200000000000000000000000000000000000000000000
          0000000000121116457C2C3CC0FF2B3BBEFF2B3ABEFF2B3ABEFF2B3ABEFF2B3B
          BEFF2C3CC0FF1116457C00000012000000000000000000000000000000000000
          0012101543792F3EC3FF5F71F9FF697DFFFF697CFFFF697CFFFF697CFFFF697D
          FFFF5F71F9FF2F3EC3FF10154379000000120000000000000000000000121015
          43792F3EC2FF586BF6FF5F74FFFF5D72FEFF5E72FDFF5E73FDFF5E72FDFF5D72
          FEFF5F74FFFF586BF6FF2F3EC2FF1015437900000012000000001116457C303F
          C2FF5568F3FF586CFCFF4E64F9FF4D63F8FF5468F9FF576BF9FF5468F9FF4D63
          F8FF4E64F9FF586CFCFF5568F3FF303FC2FF1116457C000000002D3DC0FF5367
          F2FF556BFAFF4960F7FFFFFFFFFFFFFFFFFF3E56F6FF475EF6FF3E56F6FFFFFF
          FFFFFFFFFFFF4960F7FF556BFAFF5166F2FF2D3DC0FF000000002B3BBFFF6276
          FCFF4D64F6FF4259F4FFFFFFFFFFFFFFFFFFFFFFFFFF2C46F3FFFFFFFFFFFFFF
          FFFFFFFFFFFF4259F4FF4E64F6FF5F75FCFF2C3BBFFF000000002A3ABFFF7386
          FAFF495FF3FF435AF3FF6E80F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFF6E80F6FF435AF3FF495FF3FF6E81FAFF2B3ABFFF000000002939BFFF8696
          FBFF425AF1FF4259F1FF354EF0FF5B70F2FFFFFFFFFFFFFFFFFFFFFFFFFF5B70
          F2FF354EF0FF4259F1FF435BF1FF7D90F9FF2A39BFFF000000002737BFFF9AA8
          FBFF3A55EFFF3953EEFF2844EDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFF2844EDFF3953EEFF3B55EFFF8E9DFAFF2838BFFF000000002637BFFF9FAB
          F1FF314CEDFF2B47EBFFFFFFFFFFFFFFFFFFFFFFFFFF5369EFFFFFFFFFFFFFFF
          FFFFFFFFFFFF2C47EBFF314CEDFF9FABF1FF2737BFFF000000002838C1FF9FAB
          F1FF8091F4FF213EE8FFFFFFFFFFFFFFFFFF5D72EEFF2340E8FF5D72EEFFFFFF
          FFFFFFFFFFFF213EE8FF8091F4FF9FABF1FF2838C1FF000000001016455B2E3E
          C3FF97A5EFFF778AF2FF5B71EEFF6074EEFF2643E6FF2C48E7FF2643E6FF6074
          EEFF5B71EEFF778AF2FF97A5EFFF2E3EC3FF1016455B00000000000000000F15
          43582E3EC2FF95A2EEFF7688F0FF1E3BE4FF2340E5FF2541E5FF2340E5FF1E3B
          E4FF7688F0FF95A2EEFF2E3EC2FF0F1543580000000000000000000000000000
          00000F1543582F3DC3FF94A0EFFFADB9F8FFADB8F7FFADB9F7FFADB8F7FFADB9
          F8FF94A0EFFF2F3DC3FF0F154358000000000000000000000000000000000000
          0000000000001015455B303FC4FF4555CEFF4454CDFF4354CDFF4454CDFF4555
          CEFF303FC4FF1015455B00000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000414141473636
          363602020202000000000000000010101010AFAFAFB3F3F4F4FFCBCBCBD20505
          050526262626DBDBDBFCCFCFCFFF8787879A2626262600000000C5C8CAFF9599
          9CDF1F1F1F1F000000000000000013131313C7C7C7C9B6B5B5FF929291F15C5B
          5B6717171717ABABABE66C6C6CFF797A7AFFC1C1C1E744444444818487BB7C86
          8CFF818586AD3C3C3C3C27272728525151799FA1A2E7989A9BFF4A4D4EFF838A
          91F45B5B5E624342424A797979E6454545FF6E6E6FFFD6D6D6E9161717177F83
          85BB939C9FFFA4A5A5DE959594D67E7F7FFF515557FF555D60FF5F6B70FF535E
          67FF97989AEE5454545C9D9D9DB96F7172FF20282BFF97989AFF000000003232
          32329B9FA1EB6F777DFF6C747DFF6F7579FF595B5DFF293236FF536269FF898E
          8EFFA3A1A1FFBEBEBEF7EBE8E9F2D6D2D5FF4F565CFF404648FF000000002525
          2525A6A8A8E24A5A69FF3D5472FF52627BFF545E62FF354246FF3C484CFF7075
          79FFA6A7AAFFE8E9E8FFC3C8C5FFC7CEC7FF949E9DFF354146FF000000002626
          262A858D8EE4435561FF3A516EFF31455DFF33444AFF304148FF4F595FFF8D91
          94FF78787BB09797969B419E76E812AE6DFF53A180FF535A65FF000000007677
          778365757CF9344248FF394248FF2F4049FF30454BFF263E53FF586879FFAAAB
          ACFF89898CAB3C35323E00713DAB00E89DFF4AB789FF6F6F79FF000000007374
          758252666EF92C3E45FF2C3539FF19282EFF304147FF36495DFF45576DFF434E
          55FF727784FF979292B81B8E5FC900DB9BFF38A377FF7F7F87FF000000001D1D
          1D2C566064E8263842FF18262EFF081920FF29383EFF3C4247FF434F55FF606D
          73FF5A616BFF7B8081FC34AD7EFD05D79EFF17865DFF97959DED000000001414
          14147E7E7EB63E4F56FF122832FF0A1E26FF192830FF323D42FF4C585CFF6976
          7BFF70767EFF535D60FF24986DFF0DD4A0FF44AE83FF4E474A5B000000001C1C
          1C1C89898AC0374B54FF0E2934FF0C222CFF192B32FF283B43FF44565CFF5B6B
          70FF6E747EFF5E6269FF2F966EFF21DBADFF218458C908080808000000001F1F
          1F1F8C8D8FC55B6B72F8344A53FF172D36FF162B34FF22353EFF2B3E46FF4B59
          61FF56676BFF306652FF1A9C6FFF1ED8B0FF007547CA00261160000000000000
          000022222225404143576D7174A5828E92FF20343CFF152831FF1A2F38FF2D3A
          44FF3B5751F5269E6BF320C9A4FF00BD9CFF29CBA6FF1A8D58E9000000000000
          000000000000000000000E0E0E0E77777887707779DD3E4F56FF0C2029FF3A45
          4BFF7B7C7DCD18422B613FB390EB4FD9C3FF3DAA88E60D291B48000000000000
          0000000000000000000000000000000000001D1D1D1D6A6D6E899EA6A8FDADB0
          B1FF625F6066000000000C3D246732A36FE6082D185100000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000000000000000000001E000000310000003300000033000000330000
          00310000001E0000000000000000000000000000000000000000000000000000
          00000000000E000000331B2471AA2B3ABAF92B3BBEFF2B3ABEFF2B3BBEFF2B3A
          BAF91B2471AA000000330000000E000000000000000000000000000000000000
          000E0D11356B2B3BBEFF4A5BE2FF6175FCFF697DFFFF697CFFFF697DFFFF6175
          FCFF4A5BE2FF2B3BBEFF0D11356B0000000E0000000000000000000000000D11
          356B2F3FC2FF596DF6FF6276FFFF6074FEFF5F73FEFF5F73FDFF5F73FEFF6074
          FEFF6276FFFF596DF6FF2F3FC2FF0D11356B00000000000000000000001E2C3C
          BFFF5669F4FF5D71FCFF5B6FFAFF5A6EF9FF5A6EF9FF5A6EF9FF5A6EF9FF5A6E
          F9FF5B6FFAFF5D71FCFF5669F4FF2C3CBFFF0000001E000000001B2471A94256
          DEFF576DFBFF5369F8FF5268F7FF5267F7FF5267F7FF5267F7FF5267F7FF5267
          F7FF5268F7FF5369F8FF576DFBFF4256DEFF1B2471A9000000002C3CBAF94E64
          F4FF4C63F7FF425AF4FF3E56F4FF3D55F4FF3D55F4FF3D55F4FF3D55F4FF3D55
          F4FF3E56F4FF425AF4FF4C63F7FF4E64F4FF2C3CBAF9000000002C3CBFFF5369
          F8FF3E56F3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFF3E56F3FF5369F8FF2C3CBFFF000000002B3BBFFF6378
          F7FF334DF0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFF334DF0FF6378F7FF2B3BBFFF000000002A39BFFF8696
          F8FF2F4BEEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFF2F4BEEFF8696F8FF2A39BFFF000000002837BAF8A1AC
          F4FF3852EDFF2D48ECFF2B46EBFF2A46EBFF2A46EBFF2A46EBFF2A46EBFF2A46
          EBFF2B46EBFF2D48ECFF3852EDFFA1ACF4FF2837BAF800000000192271956F7C
          DDFF8494F5FF2E4AE9FF334DE9FF354FEAFF3650EAFF3650EAFF3650EAFF354F
          EAFF334DE9FF2E4AE9FF8494F5FF6F7CDDFF1922719500000000000000002737
          BFFF9AA7F0FF7F90F3FF324CE9FF2D49E7FF304CE8FF314CE8FF304CE8FF2D49
          E7FF324CE9FF7F90F3FF9AA7F0FF2737BFFF0000000000000000000000000C11
          35462F3FC3FF97A3EFFF9EACF7FF6075EDFF3E57E9FF2441E5FF3E57E9FF6075
          EDFF9EACF7FF97A3EFFF2F3FC3FF0C1135460000000000000000000000000000
          00000C1035462737BFFF6A77DCFF9EA9F2FFAFBAF8FFAFBBF8FFAFBAF8FF9EA9
          F2FF6A77DCFF2737BFFF0C103546000000000000000000000000000000000000
          00000000000000000000192271952736BAF72737BFFF2737BFFF2737BFFF2736
          BAF7192271950000000000000000000000000000000000000000}
      end>
  end
  object TcpClient1: TTcpClient
    Left = 16
    Top = 192
  end
  object ipsHTTPS1: TipsHTTPS
    SSLCertStore = 'MY'
    TransferredDataLimit = 65536
    Left = 16
    Top = 256
  end
  object ipsJSONS1: TipsJSONS
    SSLCertStore = 'MY'
    OnSSLServerAuthentication = ipsJSONS1SSLServerAuthentication
    Left = 16
    Top = 144
  end
end
