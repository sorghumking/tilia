object YaxesForm: TYaxesForm
  Left = 1221
  Top = 212
  Hint = 'Y-axes dialog box'
  HelpContext = 51
  BorderIcons = [biSystemMenu, biHelp]
  Caption = 'Y-axes'
  ClientHeight = 395
  ClientWidth = 611
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  ShowHint = True
  OnActivate = FormActivate
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnDeactivate = FormDeactivate
  OnHelp = FormHelp
  DesignSize = (
    611
    395)
  PixelsPerInch = 96
  TextHeight = 13
  object FlowPanel1: TFlowPanel
    Left = 444
    Top = 361
    Width = 150
    Height = 25
    Anchors = [akLeft, akBottom]
    AutoWrap = False
    BevelOuter = bvNone
    TabOrder = 0
    object Button1: TButton
      Left = 0
      Top = 0
      Width = 50
      Height = 25
      Caption = '&Ok'
      ModalResult = 1
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 50
      Top = 0
      Width = 50
      Height = 25
      Caption = '&Cancel'
      ModalResult = 2
      TabOrder = 1
    end
    object Button3: TButton
      Left = 100
      Top = 0
      Width = 50
      Height = 25
      Caption = '&Help'
      TabOrder = 2
      OnClick = Button3Click
    end
  end
  object Panel5: TPanel
    Left = 8
    Top = 16
    Width = 413
    Height = 369
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    object cxPageControl1: TcxPageControl
      Left = 8
      Top = 104
      Width = 369
      Height = 249
      TabOrder = 1
      Properties.ActivePage = cxTabSheet1
      Properties.CustomButtons.Buttons = <>
      Properties.NavigatorPosition = npRightBottom
      Properties.Style = 9
      Properties.TabPosition = tpBottom
      Properties.TabSlants.Kind = skCutCorner
      Properties.TabSlants.Positions = []
      LookAndFeel.Kind = lfFlat
      LookAndFeel.NativeStyle = False
      TabSlants.Kind = skCutCorner
      TabSlants.Positions = []
      ClientRectBottom = 229
      ClientRectRight = 369
      ClientRectTop = 0
      object cxTabSheet1: TcxTabSheet
        Hint = 'Axis and scale limits'
        HelpContext = 53
        Caption = 'Limits'
        ImageIndex = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object GroupBox1: TGroupBox
          Left = 128
          Top = 16
          Width = 105
          Height = 185
          Hint = 'Axis limits'
          HelpContext = 53
          Caption = 'Axis Limits'
          TabOrder = 0
          object GroupBox3: TGroupBox
            Left = 8
            Top = 24
            Width = 89
            Height = 73
            Caption = 'Minimum'
            TabOrder = 0
            object CheckBox1: TCheckBox
              Left = 8
              Top = 16
              Width = 73
              Height = 17
              Hint = 'Check this box to automatically determine minimum axis limits'
              HelpContext = 53
              Caption = 'Automatic'
              TabOrder = 0
              OnClick = CheckBox1Click
            end
            object Edit1: TEdit
              Left = 8
              Top = 40
              Width = 73
              Height = 21
              Hint = 'Minimum axis limits if Automatic is not checked'
              HelpContext = 53
              TabOrder = 1
            end
          end
          object GroupBox4: TGroupBox
            Left = 8
            Top = 104
            Width = 89
            Height = 73
            HelpContext = 53
            Caption = 'Maximum'
            TabOrder = 1
            object CheckBox2: TCheckBox
              Left = 8
              Top = 16
              Width = 73
              Height = 17
              Hint = 'Check this box to automatically determine maximum axis limits'
              HelpContext = 53
              Caption = 'Automatic'
              TabOrder = 0
              OnClick = CheckBox2Click
            end
            object Edit2: TEdit
              Left = 8
              Top = 40
              Width = 73
              Height = 21
              Hint = 'Maximum axis limits if Automatic is not checked'
              HelpContext = 53
              TabOrder = 1
            end
          end
        end
        object GroupBox2: TGroupBox
          Left = 248
          Top = 16
          Width = 105
          Height = 185
          HelpContext = 53
          Caption = 'Scale Limits'
          TabOrder = 1
          object GroupBox5: TGroupBox
            Left = 8
            Top = 24
            Width = 89
            Height = 73
            HelpContext = 53
            Caption = 'Mimimum'
            TabOrder = 0
            object CheckBox3: TCheckBox
              Left = 8
              Top = 16
              Width = 73
              Height = 17
              Hint = 'Check this box to automatically determine minimum scale limits'
              HelpContext = 53
              Caption = 'Automatic'
              TabOrder = 0
              OnClick = CheckBox3Click
            end
            object Edit3: TEdit
              Left = 8
              Top = 40
              Width = 73
              Height = 21
              Hint = 'Minimum scale limits if Automatic is not checked'
              TabOrder = 1
            end
          end
          object GroupBox6: TGroupBox
            Left = 8
            Top = 104
            Width = 89
            Height = 73
            HelpContext = 53
            Caption = 'Maximum'
            TabOrder = 1
            object CheckBox4: TCheckBox
              Left = 8
              Top = 16
              Width = 73
              Height = 17
              Hint = 'Check this box to automatically determine maximum scale limits'
              HelpContext = 53
              Caption = 'Automatic'
              TabOrder = 0
              OnClick = CheckBox4Click
            end
            object Edit4: TEdit
              Left = 8
              Top = 40
              Width = 73
              Height = 21
              Hint = 'Maximum scale limits if Automatic is not checked'
              HelpContext = 53
              TabOrder = 1
            end
          end
        end
        object GroupBox11: TGroupBox
          Left = 8
          Top = 16
          Width = 105
          Height = 185
          Hint = 'Axis limits'
          HelpContext = 53
          Caption = 'Data Limits'
          Ctl3D = True
          ParentCtl3D = False
          TabOrder = 2
          object GroupBox12: TGroupBox
            Left = 8
            Top = 24
            Width = 89
            Height = 73
            Caption = 'Minimum'
            TabOrder = 0
            object CheckBox7: TCheckBox
              Left = 8
              Top = 16
              Width = 73
              Height = 17
              Hint = 'Check this box to automatically determine minimum axis limits'
              HelpContext = 53
              Caption = 'Automatic'
              TabOrder = 0
              OnClick = CheckBox7Click
            end
            object Edit5: TEdit
              Left = 8
              Top = 40
              Width = 73
              Height = 21
              Hint = 'Minimum axis limits if Automatic is not checked'
              HelpContext = 53
              TabOrder = 1
            end
          end
          object GroupBox13: TGroupBox
            Left = 8
            Top = 104
            Width = 89
            Height = 73
            HelpContext = 53
            Caption = 'Maximum'
            TabOrder = 1
            object CheckBox8: TCheckBox
              Left = 8
              Top = 16
              Width = 73
              Height = 17
              Hint = 'Check this box to automatically determine maximum axis limits'
              HelpContext = 53
              Caption = 'Automatic'
              TabOrder = 0
              OnClick = CheckBox8Click
            end
            object Edit6: TEdit
              Left = 8
              Top = 40
              Width = 73
              Height = 21
              Hint = 'Maximum axis limits if Automatic is not checked'
              HelpContext = 53
              TabOrder = 1
            end
          end
        end
      end
      object cxTabSheet2: TcxTabSheet
        Hint = 'Y-axis tic marks'
        HelpContext = 58
        Caption = 'Tic Marks'
        ImageIndex = 1
        ExplicitWidth = 0
        ExplicitHeight = 0
        object GroupBox7: TGroupBox
          Left = 8
          Top = 8
          Width = 113
          Height = 113
          Hint = 'Step size'
          HelpContext = 59
          Caption = 'Step Size'
          TabOrder = 0
          object CheckBox5: TCheckBox
            Left = 8
            Top = 24
            Width = 81
            Height = 17
            Hint = 'Check this box to automatically determine tic mark step size'
            HelpContext = 59
            Caption = 'Automatic'
            TabOrder = 0
            OnClick = CheckBox5Click
          end
          object LabeledEdit5: TLabeledEdit
            Left = 40
            Top = 48
            Width = 65
            Height = 21
            Hint = 'Step size between minor tic marks if Automatic is not checked'
            HelpContext = 59
            EditLabel.Width = 30
            EditLabel.Height = 13
            EditLabel.Caption = 'Minor:'
            LabelPosition = lpLeft
            TabOrder = 1
          end
          object LabeledEdit6: TLabeledEdit
            Left = 40
            Top = 80
            Width = 65
            Height = 21
            Hint = 'Step size between major tic marks if Automatic is not checked'
            HelpContext = 59
            EditLabel.Width = 31
            EditLabel.Height = 13
            EditLabel.Caption = 'Major:'
            LabelPosition = lpLeft
            TabOrder = 2
          end
        end
        object GroupBox8: TGroupBox
          Left = 136
          Top = 8
          Width = 212
          Height = 161
          Caption = 'Tic Mark Labels'
          TabOrder = 1
          object LabeledEdit2: TLabeledEdit
            Left = 136
            Top = 24
            Width = 65
            Height = 21
            Hint = 'Distance between tic mark and label in virtual units'
            HelpContext = 33
            EditLabel.Width = 114
            EditLabel.Height = 13
            EditLabel.Caption = 'Distance From Tic Mark:'
            LabelPosition = lpLeft
            TabOrder = 0
          end
          object LabeledEdit3: TLabeledEdit
            Left = 136
            Top = 56
            Width = 65
            Height = 21
            Hint = 'Factor by which tic mark labels are divided'
            HelpContext = 34
            EditLabel.Width = 48
            EditLabel.Height = 13
            EditLabel.Caption = 'Divide by:'
            LabelPosition = lpLeft
            TabOrder = 1
          end
          object LabeledEdit4: TLabeledEdit
            Left = 136
            Top = 88
            Width = 65
            Height = 21
            Hint = 'Number of decimal points in tic mark labels'
            HelpContext = 35
            EditLabel.Width = 125
            EditLabel.Height = 13
            EditLabel.Caption = 'Number of Decimal Points:'
            LabelPosition = lpLeft
            TabOrder = 2
          end
        end
        object GroupBox9: TGroupBox
          Left = 8
          Top = 128
          Width = 113
          Height = 89
          Hint = 'Lenths of tic marks in virtual units'
          HelpContext = 60
          Caption = 'Lengths'
          Ctl3D = True
          ParentCtl3D = False
          TabOrder = 2
          object LabeledEdit7: TLabeledEdit
            Left = 40
            Top = 24
            Width = 65
            Height = 21
            Hint = 'Length of minor tic marks in virtual units'
            HelpContext = 60
            EditLabel.Width = 30
            EditLabel.Height = 13
            EditLabel.Caption = 'Minor:'
            LabelPosition = lpLeft
            TabOrder = 0
          end
          object LabeledEdit8: TLabeledEdit
            Left = 40
            Top = 56
            Width = 65
            Height = 21
            Hint = 'Length of major tic marks in virtual units'
            HelpContext = 60
            EditLabel.Width = 31
            EditLabel.Height = 13
            EditLabel.Caption = 'Major:'
            LabelPosition = lpLeft
            TabOrder = 1
          end
        end
        object cxButton3: TcxButton
          Left = 272
          Top = 120
          Width = 65
          Height = 25
          Caption = 'Font'
          LookAndFeel.Kind = lfOffice11
          OptionsImage.ImageIndex = 2
          OptionsImage.Images = cxImageList1
          TabOrder = 3
          OnClick = cxButton3Click
        end
      end
      object cxTabSheet3: TcxTabSheet
        Hint = 'Scale label'
        HelpKeyword = '0'
        HelpContext = 61
        Caption = 'Label'
        ImageIndex = 2
        ExplicitWidth = 0
        ExplicitHeight = 0
        object Panel3: TPanel
          Left = 36
          Top = 16
          Width = 289
          Height = 185
          Hint = 'Scale label'
          BevelInner = bvRaised
          BevelOuter = bvLowered
          TabOrder = 0
          object Panel2: TPanel
            Left = 12
            Top = 12
            Width = 266
            Height = 121
            Hint = 'Scale label'
            BevelInner = bvRaised
            BevelOuter = bvLowered
            TabOrder = 0
            object RadioGroup1: TRadioGroup
              Left = 12
              Top = 8
              Width = 113
              Height = 89
              Hint = 'Position of scale label'
              HelpContext = 62
              Caption = 'Position'
              Items.Strings = (
                'Automatic Side'
                'Automatic Top'
                'User Defined:')
              TabOrder = 0
              OnClick = RadioGroup1Click
            end
            object GroupBox10: TGroupBox
              Left = 140
              Top = 8
              Width = 113
              Height = 73
              Hint = 'Coordinates of scale label in virtual units'
              HelpContext = 63
              Caption = 'Coordinates:'
              TabOrder = 1
              object LabeledEdit10: TLabeledEdit
                Left = 24
                Top = 16
                Width = 81
                Height = 21
                Hint = 'X-coordinate of scale label in virtual units'
                HelpContext = 63
                EditLabel.Width = 10
                EditLabel.Height = 13
                EditLabel.Caption = 'X:'
                LabelPosition = lpLeft
                TabOrder = 0
              end
              object LabeledEdit11: TLabeledEdit
                Left = 24
                Top = 44
                Width = 81
                Height = 21
                Hint = 'Y-coordinate of scale label in virtual units'
                HelpContext = 63
                EditLabel.Width = 10
                EditLabel.Height = 13
                EditLabel.Caption = 'Y:'
                LabelPosition = lpLeft
                TabOrder = 1
              end
            end
            object LabeledEdit12: TLabeledEdit
              Left = 172
              Top = 90
              Width = 81
              Height = 21
              Hint = 'Angle of the scale label'
              HelpContext = 64
              EditLabel.Width = 31
              EditLabel.Height = 13
              EditLabel.Caption = 'Angle:'
              LabelPosition = lpLeft
              TabOrder = 2
            end
          end
          object cxButton4: TcxButton
            Left = 12
            Top = 148
            Width = 65
            Height = 25
            Caption = 'Font'
            LookAndFeel.Kind = lfOffice11
            OptionsImage.ImageIndex = 2
            OptionsImage.Images = cxImageList1
            TabOrder = 1
            OnClick = cxButton4Click
          end
        end
      end
      object cxTabSheet4: TcxTabSheet
        Hint = 'Scale properties'
        HelpContext = 65
        Caption = 'Properties'
        ImageIndex = 3
        ExplicitWidth = 0
        ExplicitHeight = 0
        object Panel4: TPanel
          Left = 104
          Top = 24
          Width = 153
          Height = 153
          Hint = 'Scale properties'
          BevelInner = bvRaised
          BevelOuter = bvLowered
          TabOrder = 0
          object Label16: TLabel
            Left = 16
            Top = 64
            Width = 82
            Height = 13
            Caption = 'Scale Line Width:'
            FocusControl = LineWidthComboBox1
          end
          object Label1: TLabel
            Left = 16
            Top = 12
            Width = 57
            Height = 13
            Caption = 'Scale Color:'
          end
          object LineWidthComboBox1: TComboBox
            Left = 16
            Top = 78
            Width = 75
            Height = 21
            Hint = 'Scale line width'
            HelpContext = 6
            TabOrder = 0
          end
          object CheckBox6: TCheckBox
            Left = 16
            Top = 120
            Width = 129
            Height = 17
            Hint = 'Check this box to apply to all scales'
            HelpContext = 66
            Caption = 'Apply to all scales'
            TabOrder = 1
          end
          object ColorBox3: TColorBox
            Left = 16
            Top = 28
            Width = 121
            Height = 22
            Hint = 'Scale color'
            HelpContext = 7
            Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
            TabOrder = 2
            OnChange = ColorBox3Change
          end
        end
      end
    end
    object YaxisGrid: TcxGrid
      Left = 8
      Top = 8
      Width = 369
      Height = 97
      Hint = 'Available axes'
      HelpContext = 52
      TabOrder = 0
      LookAndFeel.Kind = lfUltraFlat
      LookAndFeel.NativeStyle = False
      LookAndFeel.SkinName = 'Lilian'
      object YaxisGridTableView: TcxGridTableView
        Navigator.Buttons.CustomButtons = <>
        OnFocusedRecordChanged = YaxisGridTableViewFocusedRecordChanged
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        OptionsBehavior.AlwaysShowEditor = True
        OptionsBehavior.FocusCellOnTab = True
        OptionsBehavior.GoToNextCellOnEnter = True
        OptionsBehavior.FocusCellOnCycle = True
        OptionsCustomize.ColumnFiltering = False
        OptionsCustomize.ColumnGrouping = False
        OptionsCustomize.ColumnMoving = False
        OptionsCustomize.ColumnSorting = False
        OptionsData.CancelOnExit = False
        OptionsData.Deleting = False
        OptionsData.Inserting = False
        OptionsSelection.HideFocusRectOnExit = False
        OptionsView.CellEndEllipsis = True
        OptionsView.ColumnAutoWidth = True
        OptionsView.GroupByBox = False
        OptionsView.HeaderEndEllipsis = True
        OptionsView.Indicator = True
        object yaCode: TcxGridColumn
          Caption = 'Code'
          PropertiesClassName = 'TcxTextEditProperties'
          HeaderAlignmentHorz = taCenter
          Options.Editing = False
          Options.Filtering = False
          Options.Focusing = False
          Options.IncSearch = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 60
        end
        object yaName: TcxGridColumn
          Caption = 'Name'
          PropertiesClassName = 'TcxTextEditProperties'
          HeaderAlignmentHorz = taCenter
          MinWidth = 100
          Options.Filtering = False
          Options.IncSearch = False
          Options.Grouping = False
          Options.Moving = False
          Options.Sorting = False
          Width = 258
        end
        object yaPlot: TcxGridColumn
          Caption = 'Plot'
          DataBinding.ValueType = 'Boolean'
          PropertiesClassName = 'TcxCheckBoxProperties'
          Properties.Alignment = taCenter
          Properties.OnChange = yaPlotPropertiesChange
          HeaderAlignmentHorz = taCenter
          MinWidth = 40
          Options.Filtering = False
          Options.IncSearch = False
          Options.Grouping = False
          Options.HorzSizing = False
          Options.Moving = False
          Options.Sorting = False
          Width = 40
        end
      end
      object YaxisGridLevel1: TcxGridLevel
        GridView = YaxisGridTableView
      end
    end
    object FlowPanel2: TFlowPanel
      Left = 381
      Top = 28
      Width = 25
      Height = 50
      AutoSize = True
      BevelOuter = bvNone
      TabOrder = 2
      object cxButton1: TcxButton
        Left = 0
        Top = 0
        Width = 25
        Height = 25
        LookAndFeel.Kind = lfOffice11
        OptionsImage.ImageIndex = 0
        OptionsImage.Images = cxImageList1
        TabOrder = 0
        OnClick = cxButton1Click
      end
      object cxButton2: TcxButton
        Left = 0
        Top = 25
        Width = 25
        Height = 25
        LookAndFeel.Kind = lfOffice11
        OptionsImage.ImageIndex = 1
        OptionsImage.Images = cxImageList1
        TabOrder = 1
        OnClick = cxButton2Click
      end
    end
  end
  object Panel1: TPanel
    Left = 436
    Top = 16
    Width = 166
    Height = 297
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    object RadioGroup2: TRadioGroup
      Left = 12
      Top = 12
      Width = 113
      Height = 93
      Hint = 'Scale style'
      HelpContext = 54
      Caption = 'Scale Style'
      Items.Strings = (
        'Standard'
        'Column'
        'Sample Names')
      TabOrder = 0
    end
    object LabeledEdit1: TLabeledEdit
      Left = 12
      Top = 136
      Width = 77
      Height = 21
      Hint = 'Axis length in virtual units'
      HelpContext = 55
      EditLabel.Width = 60
      EditLabel.Height = 13
      EditLabel.Caption = 'Axis Length:'
      TabOrder = 1
    end
    object LabeledEdit13: TLabeledEdit
      Left = 12
      Top = 200
      Width = 77
      Height = 21
      Hint = 
        'Vertical distance between the ends of the Y-axis and data in vir' +
        'tual units '
      HelpContext = 56
      EditLabel.Width = 128
      EditLabel.Height = 26
      EditLabel.HelpContext = 1527
      EditLabel.Caption = 'Distance Between Ends of Y-axis and Data'
      EditLabel.WordWrap = True
      TabOrder = 2
    end
    object LabeledEdit14: TLabeledEdit
      Left = 12
      Top = 264
      Width = 77
      Height = 21
      Hint = 
        'Horizontal space between the scale and the first graph in virtua' +
        'l units'
      HelpContext = 57
      EditLabel.Width = 126
      EditLabel.Height = 26
      EditLabel.HelpContext = 1528
      EditLabel.Caption = 'Space Between Scale and First Graph:'
      EditLabel.WordWrap = True
      TabOrder = 3
    end
  end
  object ColorDialog1: TColorDialog
    Left = 408
    Top = 232
  end
  object cxImageList1: TcxImageList
    FormatVersion = 1
    DesignInfo = 20971952
    ImageInfo = <
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000008A6A39F2986F44FFA0764AFFA4784BFFA375
          46FFA17B42F00000000000000000000000000000000000000000000000000000
          0000000000000000000000000001936A40FFD6A17DFFE5B28FFFE5B28FFFD5A0
          7CFFA57646FE0000000000000000000000000000000000000000000000000000
          0000000000000000000000000001906841FFD5A07CFFE3B08DFFE3AF8CFFD49F
          7BFF9B6F46FE0000000000000000000000000000000000000000000000000000
          000000000000000000000000000186603EFFCB9571FFD49F7BFFD49F7BFFCA95
          70FF8B6441FE0000000000000000000000000000000000000000000000001F17
          0C4B211208801F1006801D1006807D5839FFBC8660FFC38D68FFC28D67FFBC85
          60FF7D593AFE231409802D190B803B22108020180F3200000000000000004031
          1B946F4626FF805231FF936340FFA1704CFFAC7854FFB27E59FFB07B55FFA872
          4DFF9D6945FF8D5C38FF7A4A29FF704421FF67522E8F00000000000000000301
          001150331DE1876244FF946D4FFF9F7758FFA87F5EFFAC8362FFAD8565FFAA82
          63FFA0795BFF936C4FFF835C41FF714323E80B06031700000000000000000000
          00001008033F755439FC927053FF9A7759FFA07C5EFFA37F60FFA37F60FFA07C
          5DFF997658FF906E51FF8B6243FD251408480000000000000000000000000000
          0000000000002A180B84937458FF9B7D60FF9E7F62FFA08063FF9F8063FF9D7E
          61FF9A7B5FFF997759FF512D158D000000000000000000000000000000000000
          00000000000001000004553924C8A98D71FFA98D70FFA98D70FFA98D70FFA98C
          70FFA98D70FF83522FCD03010106000000000000000000000000000000000000
          000000000000000000000B0502238D6E54F2B99F82FFB89F82FFB89F82FFB89F
          82FFA77C59F3160C052600000000000000000000000000000000000000000000
          000000000000000000000000000027160A5FBCA083FFC9B193FFC9B193FFC3A3
          84FF3E2310610000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000005C3D26A7D8C2A4FFD8C2A3FF7148
          2BA7000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000603010FA17E5FDFA77F5EDE0804
          020F000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000001D140D301F140E2F0000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000000C0A05320C0A05310000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000001010010554228E159472BE00101
          0010000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000231A0EA9D5A57EFFD7A67FFF251D
          11AA000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000E080360B38B67FFE7B492FFE7B491FFB78D
          69FF0E0904640000000000000000000000000000000000000000000000000000
          000000000000000000000603012479573BF2D29D79FFDFAB87FFDEAA87FFD29D
          78FF7B5B3EF40603012700000000000000000000000000000000000000000000
          00000000000001000004442A17C8B8835DFFC6906CFFCE9975FFCE9975FFC690
          6BFFB8825CFF442C1ACE01000006000000000000000000000000000000000000
          000000000000211106858E5E3CFFA9734EFFB6805AFFBD8661FFBC8661FFB680
          5AFFA9734EFF8E5E3CFF2112088E000000000000000000000000000000000000
          00000D06023F694329FC906242FFA07251FFAC7D5CFFB38463FFB48665FFAE81
          61FFA37658FF875636FF5F381DFD0F0702480000000000000000000000000402
          01114A2C18E27D573AFF8A6344FF966D4DFF9E7454FFA27857FFA27857FF9D74
          53FF956D4DFF977358FF8C6A52FF5B412EE80603011700000000000000005035
          22958B694EFF8E6D52FF917054FF957356FF987557FF9B7759FF9B7759FF9874
          56FF947255FF906F54FF8D6C51FF96765DFF61493A9000000000000000002F1D
          114C4C29117F4F29117F512B1280A16B42FF9C7D60FF9D7E61FF9D7E61FF9B7D
          60FFA26E47FE512B127F4E29117F4B29117F2218123200000000000000000000
          00000000000000000000000000019D6E49FFAD9175FFAD9174FFAD9174FFAD91
          74FF9C704DFE0000000000000000000000000000000000000000000000000000
          00000000000000000000000000019F7552FFC0A78AFFC0A78AFFC0A78AFFC0A7
          8AFF9D7654FE0000000000000000000000000000000000000000000000000000
          0000000000000000000000000001B48660FFD4BD9FFFD4BD9FFFD4BD9FFFD4BD
          9FFFB18560FE0000000000000000000000000000000000000000000000000000
          0000000000000000000000000001C8A386F2CB9A74FECB9A74FECA9A73FECA9A
          73FEC6A084F00000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          00330000003300000033000000330000003300000033000000000000000C0000
          003300000033000000330000003300000033000000330000000000000000B985
          45FFB68241FFB5803FFFB4803FFFB68241FFB98545FF000000002A1F1042B985
          45FFB68241FFB4803FFFB4803FFFB68241FFB98545FF0000000000000000B783
          42FFFFE2ADFFFFDDA7FFFFDAA1FFFFDEA7FFB68241FF00000000251A0E3BBC89
          48FFFFE1ABFFFFD8A0FFFFD8A2FFFFE1ACFFB78242FF0000000000000000B884
          44FFCA985BFFEEBF88FFFFDDAAFFF7C890FFB47F3EFF00000000271C0F36BC89
          49FFD9A86DFFFFD59BFFFFD69FFFD9A86CFFB78342FF00000000000000000000
          0000120D07199B6E36DDE1B47BFFFFDCAAFF795A35AC0000002D000000001C14
          0A27B27E3DFFFFD397FFFFD8A2FFB27E3CFF0000000000000000000000000000
          000000000000130D071AB47F3EFFFBD4A4FFEBBC7FFF9F7138E6000000330000
          0033B37F3EFFFFCF90FFFFD8A5FFB47F3EFF0000000000000000000000000000
          0000000000000000000078552BA7D3A46AFFFFDCABFFC5904EFFB47F3DFFB57F
          3EFFB17B3AFFFDCA87FFFFD8A7FFB57F3FFF0000000000000000000000000000
          000000000000000000000705030AB57F3EFFF9D5AAFFFDCD91FFFFE1B6FFFFE4
          BCFFFFE3BBFFF9C37FFFFED8A9FFB5803EFF0000000000000000000000000000
          00000000000000000000000000005C41217FD1A46DFFFDDBABFFCB934EFF7F59
          2AB6AA7738F6F8C179FFFDDAADFFB5803EFF0000000000000000000000000000
          000000000000000000000000000000000000B57F3DFFF7D9B2FFEDBC7CFF0000
          0031805B2DC3F5BD74FFFDDCB0FFB57F3EFF0000000000000000000000000000
          0000000000000000000000000000000000005C422180D0A671FFFFE1B9FFBD88
          45F89A6D36E4F3BA6CFFFCDFB5FFB57F3EFF0000000000000000000000000000
          00000000000000000000000000000000000000000000B57F3DFFF7DFBEFFE5BA
          80FFC78F49FFEEB362FFFCE0BBFFB57F3EFF0000000000000000000000000000
          000000000000000000000000000000000000000000005C412180D0A874FFFBE6
          C7FFE9AC56FFE8AB56FFFBE3BFFFB57F3DFF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000B57E3BFFF7E4
          CAFFF1CA93FFEBB76DFFFEEDD4FFB57F3CFF0000000000000000000000000000
          00000000000000000000000000000000000000000000000000005F432183D2AC
          7CFFFFF8E8FFFFF6E6FFFFFAEBFFB6803EFF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000007C58
          2CACB67F3CFFB57E3AFFB6803DFFAD7C3FEF0000000000000000}
      end>
  end
end
