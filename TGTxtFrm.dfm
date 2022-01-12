object TextForm: TTextForm
  Left = 414
  Top = 341
  HelpContext = 103
  BorderIcons = [biSystemMenu, biHelp]
  BorderStyle = bsDialog
  Caption = 'Text'
  ClientHeight = 446
  ClientWidth = 479
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  ShowHint = True
  OnActivate = FormActivate
  OnCreate = FormCreate
  OnDeactivate = FormDeactivate
  OnHelp = FormHelp
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 16
    Top = 8
    Width = 449
    Height = 337
    ActivePage = TabSheet1
    TabOrder = 0
    object TabSheet1: TTabSheet
      HelpContext = 104
      Caption = 'Header && Footer'
      object HbtnBold: TBitBtn
        Left = 16
        Top = 16
        Width = 25
        Height = 25
        Hint = 'Bold'
        HelpContext = 105
        DoubleBuffered = True
        Glyph.Data = {
          72010000424D7201000000000000760000002800000015000000150000000100
          040000000000FC00000000000000000000001000000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
          7777777770007777777777777777777770007777777777777777777770007777
          7777777777777777700077777777777777777777700077777777777777777777
          7000777777000000007777777000777777700077000777777000777777700077
          0007777770007777777000770007777770007777777000000077777770007777
          7770007700077777700077777770007700077777700077777770007700077777
          7000777777000000007777777000777777777777777777777000777777777777
          7777777770007777777777777777777770007777777777777777777770007777
          77777777777777777000777777777777777777777000}
        ParentDoubleBuffered = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        OnClick = HbtnBoldClick
      end
      object HBtnItalic: TBitBtn
        Left = 40
        Top = 16
        Width = 25
        Height = 25
        Hint = 'Italic'
        HelpContext = 105
        DoubleBuffered = True
        Glyph.Data = {
          72010000424D7201000000000000760000002800000015000000150000000100
          040000000000FC00000000000000000000001000000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
          7777777770007777777777777777777770007777777777777777777770007777
          7777777777777777700077777777777777777777700077777777777777777777
          7000777777000000777777777000777777770087777777777000777777778007
          7777777770007777777770087777777770007777777778007777777770007777
          7777770087777777700077777777778007777777700077777777777008777777
          7000777777777700000777777000777777777777777777777000777777777777
          7777777770007777777777777777777770007777777777777777777770007777
          77777777777777777000777777777777777777777000}
        ParentDoubleBuffered = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        OnClick = HBtnItalicClick
      end
      object GroupBox1: TGroupBox
        Left = 16
        Top = 48
        Width = 409
        Height = 153
        Hint = 'Heading'
        Caption = 'Heading'
        TabOrder = 0
        object Edit1: TEdit
          Left = 8
          Top = 16
          Width = 372
          Height = 21
          Hint = 'Heading line 1'
          HelpContext = 106
          TabOrder = 0
          OnEnter = Edit1Enter
        end
        object Edit2: TEdit
          Left = 8
          Top = 36
          Width = 372
          Height = 21
          Hint = 'Heading line 2'
          HelpContext = 106
          TabOrder = 1
          OnEnter = Edit2Enter
        end
        object Edit3: TEdit
          Left = 8
          Top = 56
          Width = 372
          Height = 21
          Hint = 'Heading line 3'
          HelpContext = 106
          TabOrder = 2
          OnEnter = Edit3Enter
        end
        object Edit4: TEdit
          Left = 8
          Top = 76
          Width = 372
          Height = 21
          Hint = 'Heading line 4'
          HelpContext = 106
          TabOrder = 3
          OnEnter = Edit4Enter
        end
        object GroupBox3: TGroupBox
          Left = 8
          Top = 104
          Width = 193
          Height = 41
          Hint = 'X-Coordinate'
          HelpContext = 107
          Caption = 'X-Coordinate'
          TabOrder = 4
          object CheckBox1: TCheckBox
            Left = 8
            Top = 16
            Width = 73
            Height = 17
            Hint = 
              'Check this box to automatically place the X-coordinate for the h' +
              'eading'
            HelpContext = 107
            Caption = 'Automatic'
            TabOrder = 0
            OnClick = CheckBox1Click
          end
          object Edit7: TEdit
            Left = 88
            Top = 12
            Width = 97
            Height = 21
            Hint = 'X-coordinate of the heading if Automatic is not checked'
            HelpContext = 107
            TabOrder = 1
            OnEnter = Edit7Enter
          end
        end
        object GroupBox4: TGroupBox
          Left = 208
          Top = 104
          Width = 193
          Height = 41
          HelpContext = 108
          Caption = 'Y-Coordinate'
          TabOrder = 5
          object CheckBox2: TCheckBox
            Left = 8
            Top = 16
            Width = 73
            Height = 17
            Hint = 
              'Check this box to automatically place the Y-coordinate for the h' +
              'eading'
            HelpContext = 108
            Caption = 'Automatic'
            TabOrder = 0
            OnClick = CheckBox2Click
          end
          object Edit8: TEdit
            Left = 88
            Top = 12
            Width = 97
            Height = 21
            Hint = 'Y-coordinate of the heading if Automatic is not checked'
            HelpContext = 108
            TabOrder = 1
            OnEnter = Edit8Enter
          end
        end
        object BitBtn3: TBitBtn
          Left = 379
          Top = 16
          Width = 21
          Height = 21
          Hint = 'Font'
          HelpContext = 20
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
          OnClick = BitBtn3Click
        end
        object BitBtn9: TBitBtn
          Left = 379
          Top = 36
          Width = 21
          Height = 21
          Hint = 'Font'
          HelpContext = 20
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
          TabOrder = 7
          OnClick = BitBtn9Click
        end
        object BitBtn10: TBitBtn
          Left = 379
          Top = 56
          Width = 21
          Height = 21
          Hint = 'Font'
          HelpContext = 20
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
          TabOrder = 8
          OnClick = BitBtn10Click
        end
        object BitBtn11: TBitBtn
          Left = 379
          Top = 76
          Width = 21
          Height = 21
          Hint = 'Font'
          HelpContext = 20
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
          TabOrder = 9
          OnClick = BitBtn11Click
        end
      end
      object GroupBox2: TGroupBox
        Left = 16
        Top = 208
        Width = 409
        Height = 93
        Caption = 'Footer'
        TabOrder = 1
        object Edit5: TEdit
          Left = 8
          Top = 16
          Width = 372
          Height = 21
          Hint = 'Footer'
          HelpContext = 109
          TabOrder = 0
          OnEnter = Edit5Enter
        end
        object GroupBox5: TGroupBox
          Left = 8
          Top = 44
          Width = 193
          Height = 41
          HelpContext = 110
          Caption = 'X-Coordinate'
          TabOrder = 1
          object CheckBox3: TCheckBox
            Left = 8
            Top = 16
            Width = 73
            Height = 17
            Hint = 
              'Check this box to automatically place the X-coordinate of the fo' +
              'oter'
            HelpContext = 110
            Caption = 'Automatic'
            TabOrder = 0
            OnClick = CheckBox3Click
          end
          object Edit9: TEdit
            Left = 88
            Top = 12
            Width = 97
            Height = 21
            Hint = 'X-coordinate of the footer if Automatic is not checked'
            HelpContext = 110
            TabOrder = 1
            OnEnter = Edit9Enter
          end
        end
        object GroupBox6: TGroupBox
          Left = 208
          Top = 44
          Width = 193
          Height = 41
          HelpContext = 111
          Caption = 'Y-Coordinate'
          TabOrder = 2
          object CheckBox4: TCheckBox
            Left = 8
            Top = 16
            Width = 73
            Height = 17
            Hint = 
              'Check this box to automatically place the Y-coordinate of the fo' +
              'oter'
            HelpContext = 111
            Caption = 'Automatic'
            TabOrder = 0
            OnClick = CheckBox4Click
          end
          object Edit10: TEdit
            Left = 88
            Top = 12
            Width = 97
            Height = 21
            Hint = 'Y-coordinate of the footer if Automatic is not checked'
            HelpContext = 111
            TabOrder = 1
            OnEnter = Edit10Enter
          end
        end
        object BitBtn12: TBitBtn
          Left = 379
          Top = 16
          Width = 21
          Height = 21
          Hint = 'Font'
          HelpContext = 20
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
          TabOrder = 3
          OnClick = BitBtn12Click
        end
      end
      object HBtnSuper: TBitBtn
        Left = 64
        Top = 16
        Width = 25
        Height = 25
        Hint = 'Superscript'
        HelpContext = 105
        DoubleBuffered = True
        Glyph.Data = {
          F6000000424DF60000000000000076000000280000000C000000100000000100
          0400000000008000000000000000000000001000000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
          0000777777777777000077777777777700007777777777770000700770077777
          0000780880877777000077080077777700007780087777770000777007777777
          0000770008771111000078088087717700007007700777170000777777777717
          0000777777777771000077777777177100007777777771170000}
        ParentDoubleBuffered = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
        OnClick = HBtnSuperClick
      end
      object HBtnSub: TBitBtn
        Left = 88
        Top = 16
        Width = 25
        Height = 25
        Hint = 'Subscript'
        HelpContext = 105
        DoubleBuffered = True
        Glyph.Data = {
          D6000000424DD60000000000000076000000280000000C0000000C0000000100
          0400000000006000000000000000000000001000000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777774444
          0000777777777477000070077007774700007808808777470000770800777774
          0000778008774774000077700777744700007700087777770000780880877777
          0000700770077777000077777777777700007777777777770000}
        ParentDoubleBuffered = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 5
        OnClick = HBtnSubClick
      end
      object HBtnGreek: TBitBtn
        Left = 112
        Top = 16
        Width = 25
        Height = 25
        Hint = 'Insert Greek letter'
        HelpContext = 105
        DoubleBuffered = True
        Glyph.Data = {
          72010000424D7201000000000000760000002800000015000000150000000100
          040000000000FC00000000000000000000001000000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
          7777777770007777777777777777777770007777777777777777777770007777
          7777777777777777700077777777777777777777700077777777777777777777
          7000777777800000000777777000777777700000000777777000777777788777
          7807777770007777777788777807777770007777777780777777777770007777
          7777808777777777700077777778008777777777700077777778087780777777
          7000777777800777807777777000777777800000007777777000777777777777
          7777777770007777777777777777777770007777777777777777777770007777
          77777777777777777000777777777777777777777000}
        ParentDoubleBuffered = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 6
        OnClick = HBtnGreekClick
      end
    end
    object TabSheet2: TTabSheet
      HelpContext = 112
      Caption = 'Random Text'
      ImageIndex = 1
      OnEnter = TabSheet2Enter
      object BitBtn4: TBitBtn
        Left = 13
        Top = 16
        Width = 25
        Height = 25
        Hint = 'Bold'
        HelpContext = 105
        DoubleBuffered = True
        Glyph.Data = {
          72010000424D7201000000000000760000002800000015000000150000000100
          040000000000FC00000000000000000000001000000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
          7777777770007777777777777777777770007777777777777777777770007777
          7777777777777777700077777777777777777777700077777777777777777777
          7000777777000000007777777000777777700077000777777000777777700077
          0007777770007777777000770007777770007777777000000077777770007777
          7770007700077777700077777770007700077777700077777770007700077777
          7000777777000000007777777000777777777777777777777000777777777777
          7777777770007777777777777777777770007777777777777777777770007777
          77777777777777777000777777777777777777777000}
        ParentDoubleBuffered = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        OnClick = BitBtn4Click
      end
      object BitBtn5: TBitBtn
        Left = 37
        Top = 16
        Width = 25
        Height = 25
        Hint = 'Italic'
        HelpContext = 105
        DoubleBuffered = True
        Glyph.Data = {
          72010000424D7201000000000000760000002800000015000000150000000100
          040000000000FC00000000000000000000001000000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
          7777777770007777777777777777777770007777777777777777777770007777
          7777777777777777700077777777777777777777700077777777777777777777
          7000777777000000777777777000777777770087777777777000777777778007
          7777777770007777777770087777777770007777777778007777777770007777
          7777770087777777700077777777778007777777700077777777777008777777
          7000777777777700000777777000777777777777777777777000777777777777
          7777777770007777777777777777777770007777777777777777777770007777
          77777777777777777000777777777777777777777000}
        ParentDoubleBuffered = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = BitBtn5Click
      end
      object BitBtn6: TBitBtn
        Left = 61
        Top = 16
        Width = 25
        Height = 25
        Hint = 'Superscript'
        HelpContext = 105
        DoubleBuffered = True
        Glyph.Data = {
          F6000000424DF60000000000000076000000280000000C000000100000000100
          0400000000008000000000000000000000001000000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
          0000777777777777000077777777777700007777777777770000700770077777
          0000780880877777000077080077777700007780087777770000777007777777
          0000770008771111000078088087717700007007700777170000777777777717
          0000777777777771000077777777177100007777777771170000}
        ParentDoubleBuffered = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        OnClick = BitBtn6Click
      end
      object BitBtn7: TBitBtn
        Left = 85
        Top = 16
        Width = 25
        Height = 25
        Hint = 'Subscript'
        HelpContext = 105
        DoubleBuffered = True
        Glyph.Data = {
          D6000000424DD60000000000000076000000280000000C0000000C0000000100
          0400000000006000000000000000000000001000000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777774444
          0000777777777477000070077007774700007808808777470000770800777774
          0000778008774774000077700777744700007700087777770000780880877777
          0000700770077777000077777777777700007777777777770000}
        ParentDoubleBuffered = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        OnClick = BitBtn7Click
      end
      object BitBtn8: TBitBtn
        Left = 109
        Top = 16
        Width = 25
        Height = 25
        Hint = 'Insert Greek letter'
        HelpContext = 105
        DoubleBuffered = True
        Glyph.Data = {
          72010000424D7201000000000000760000002800000015000000150000000100
          040000000000FC00000000000000000000001000000000000000000000000000
          80000080000000808000800000008000800080800000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
          7777777770007777777777777777777770007777777777777777777770007777
          7777777777777777700077777777777777777777700077777777777777777777
          7000777777800000000777777000777777700000000777777000777777788777
          7807777770007777777788777807777770007777777780777777777770007777
          7777808777777777700077777778008777777777700077777778087780777777
          7000777777800777807777777000777777800000007777777000777777777777
          7777777770007777777777777777777770007777777777777777777770007777
          77777777777777777000777777777777777777777000}
        ParentDoubleBuffered = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
        OnClick = BitBtn8Click
      end
      object RandTextGrid: TcxGrid
        Left = 12
        Top = 56
        Width = 415
        Height = 236
        Hint = 'Random text'
        HelpContext = 112
        TabOrder = 5
        LookAndFeel.NativeStyle = False
        LookAndFeel.SkinName = 'Lilian'
        object RandTextGridTableView: TcxGridTableView
          Navigator.Buttons.CustomButtons = <>
          Navigator.Buttons.Edit.Visible = False
          Navigator.Buttons.Post.Visible = True
          Navigator.Buttons.Refresh.Visible = False
          Navigator.Buttons.SaveBookmark.Visible = False
          Navigator.Buttons.GotoBookmark.Visible = False
          Navigator.Buttons.Filter.Visible = False
          Navigator.Visible = True
          OnEditKeyUp = RandTextGridTableViewEditKeyUp
          OnFocusedItemChanged = RandTextGridTableViewFocusedItemChanged
          DataController.Summary.DefaultGroupSummaryItems = <>
          DataController.Summary.FooterSummaryItems = <>
          DataController.Summary.SummaryGroups = <>
          NewItemRow.Visible = True
          OptionsBehavior.AlwaysShowEditor = True
          OptionsBehavior.FocusCellOnTab = True
          OptionsBehavior.FocusFirstCellOnNewRecord = True
          OptionsBehavior.GoToNextCellOnEnter = True
          OptionsBehavior.NavigatorHints = True
          OptionsBehavior.FocusCellOnCycle = True
          OptionsCustomize.ColumnFiltering = False
          OptionsCustomize.ColumnGrouping = False
          OptionsCustomize.ColumnMoving = False
          OptionsData.Appending = True
          OptionsData.CancelOnExit = False
          OptionsSelection.InvertSelect = False
          OptionsView.CellEndEllipsis = True
          OptionsView.ShowEditButtons = gsebAlways
          OptionsView.ColumnAutoWidth = True
          OptionsView.GroupByBox = False
          OptionsView.HeaderEndEllipsis = True
          OptionsView.Indicator = True
          object tlText: TcxGridColumn
            Caption = 'Text'
            PropertiesClassName = 'TcxTextEditProperties'
            OnGetDisplayText = tlTextGetDisplayText
            HeaderAlignmentHorz = taCenter
            MinWidth = 80
            Options.Filtering = False
            Options.Grouping = False
            Options.Moving = False
            Width = 158
          end
          object tlFont: TcxGridColumn
            Caption = 'Font'
            DataBinding.ValueType = 'Boolean'
            PropertiesClassName = 'TcxButtonEditProperties'
            Properties.Buttons = <
              item
                Default = True
                Glyph.Data = {
                  72060000424D720600000000000036040000280000002B0000000D0000000100
                  0800000000003C02000000000000000000000001000000000000000000000000
                  80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
                  A6000020400000206000002080000020A0000020C0000020E000004000000040
                  20000040400000406000004080000040A0000040C0000040E000006000000060
                  20000060400000606000006080000060A0000060C0000060E000008000000080
                  20000080400000806000008080000080A0000080C0000080E00000A0000000A0
                  200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
                  200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
                  200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
                  20004000400040006000400080004000A0004000C0004000E000402000004020
                  20004020400040206000402080004020A0004020C0004020E000404000004040
                  20004040400040406000404080004040A0004040C0004040E000406000004060
                  20004060400040606000406080004060A0004060C0004060E000408000004080
                  20004080400040806000408080004080A0004080C0004080E00040A0000040A0
                  200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
                  200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
                  200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
                  20008000400080006000800080008000A0008000C0008000E000802000008020
                  20008020400080206000802080008020A0008020C0008020E000804000008040
                  20008040400080406000804080008040A0008040C0008040E000806000008060
                  20008060400080606000806080008060A0008060C0008060E000808000008080
                  20008080400080806000808080008080A0008080C0008080E00080A0000080A0
                  200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
                  200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
                  200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
                  2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
                  2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
                  2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
                  2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
                  2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
                  2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
                  2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
                  FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00F6F6F6F6F6F6
                  F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
                  F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
                  F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6F6F6F6F6
                  F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F600F6F6
                  F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
                  F6F6F6F6F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F600
                  F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6
                  F6F6F6F6F6F6F6F6F6F6000000F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
                  F600F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F60000000000F6F6F6F6F6F6
                  F6F6F6F6F6F6F6F6F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
                  00000000000000F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F600F6F6F6F6F6F6
                  F6F6F6F6F6F6F6F6F6F6F6000000000000000000F6F6F6F6F6F6F6F6F6F6F6F6
                  F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
                  F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6F6F6F6F6
                  F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F600F6F6
                  F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
                  F6F6F6F6F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
                  F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F600}
                Kind = bkGlyph
              end>
            Properties.OnButtonClick = tlFontPropertiesButtonClick
            HeaderAlignmentHorz = taCenter
            MinWidth = 48
            Options.Filtering = False
            Options.Grouping = False
            Options.HorzSizing = False
            Options.Moving = False
            Options.Sorting = False
            Width = 48
          end
          object tlXCoord: TcxGridColumn
            Caption = 'X'
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxTextEditProperties'
            Properties.Alignment.Horz = taRightJustify
            Properties.BeepOnError = True
            Properties.UseLeftAlignmentOnEditing = False
            Properties.ValidateOnEnter = True
            Properties.OnValidate = tlXCoordPropertiesValidate
            HeaderAlignmentHorz = taCenter
            Options.Filtering = False
            Options.Grouping = False
            Options.Moving = False
            Width = 49
          end
          object tlYCoord: TcxGridColumn
            Caption = 'Y'
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxTextEditProperties'
            Properties.Alignment.Horz = taRightJustify
            Properties.BeepOnError = True
            Properties.UseLeftAlignmentOnEditing = False
            Properties.ValidateOnEnter = True
            Properties.OnValidate = tlYCoordPropertiesValidate
            HeaderAlignmentHorz = taCenter
            Options.Filtering = False
            Options.Grouping = False
            Options.Moving = False
            Width = 48
          end
          object tlAngle: TcxGridColumn
            Caption = 'Angle'
            DataBinding.ValueType = 'Float'
            PropertiesClassName = 'TcxTextEditProperties'
            Properties.Alignment.Horz = taRightJustify
            Properties.BeepOnError = True
            Properties.UseLeftAlignmentOnEditing = False
            Properties.ValidateOnEnter = True
            Properties.OnValidate = tlAnglePropertiesValidate
            HeaderAlignmentHorz = taCenter
            Options.Filtering = False
            Options.Grouping = False
            Options.Moving = False
            Options.Sorting = False
            Width = 49
          end
        end
        object RandTextGridLevel1: TcxGridLevel
          GridView = RandTextGridTableView
        end
      end
    end
  end
  object GroupBox7: TGroupBox
    Left = 16
    Top = 352
    Width = 449
    Height = 41
    Hint = 'X and Y limits of the diagram'
    Caption = 'Diagram Limits'
    TabOrder = 1
    object StaticText1: TStaticText
      Left = 8
      Top = 20
      Width = 174
      Height = 17
      Caption = 'Left = , Right = , Bottom = , Top ='
      TabOrder = 0
    end
  end
  object Button11: TButton
    Left = 16
    Top = 408
    Width = 75
    Height = 25
    Caption = '&Ok'
    ModalResult = 1
    TabOrder = 2
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 104
    Top = 408
    Width = 75
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object Button13: TButton
    Left = 192
    Top = 408
    Width = 75
    Height = 25
    Caption = '&Help'
    TabOrder = 4
    OnClick = Button13Click
  end
end
