object GroupForm: TGroupForm
  Left = 412
  Top = 214
  Hint = 'Groups dialog box'
  HelpContext = 75
  BorderIcons = [biSystemMenu, biHelp]
  BorderStyle = bsDialog
  Caption = 'Groups'
  ClientHeight = 236
  ClientWidth = 579
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  ShowHint = True
  OnActivate = FormActivate
  OnDeactivate = FormDeactivate
  OnHelp = FormHelp
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 160
    Top = 200
    Width = 75
    Height = 25
    Caption = '&Ok'
    ModalResult = 1
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 248
    Top = 200
    Width = 75
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object Button3: TButton
    Left = 336
    Top = 200
    Width = 75
    Height = 25
    Caption = '&Help'
    TabOrder = 2
    OnClick = Button3Click
  end
  object GroupsGrid: TcxGrid
    Left = 12
    Top = 16
    Width = 557
    Height = 169
    Hint = 'Enter groups'
    HelpContext = 75
    TabOrder = 3
    LookAndFeel.NativeStyle = False
    LookAndFeel.SkinName = 'Lilian'
    object GroupsGridTableView: TcxGridTableView
      Navigator.Buttons.CustomButtons = <>
      Navigator.Buttons.Edit.Visible = False
      Navigator.Buttons.Post.Visible = True
      Navigator.Buttons.Refresh.Visible = False
      Navigator.Buttons.SaveBookmark.Visible = False
      Navigator.Buttons.GotoBookmark.Visible = False
      Navigator.Buttons.Filter.Visible = False
      Navigator.Visible = True
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
      OptionsSelection.HideFocusRectOnExit = False
      OptionsSelection.InvertSelect = False
      OptionsView.CellEndEllipsis = True
      OptionsView.ShowEditButtons = gsebAlways
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      OptionsView.HeaderEndEllipsis = True
      OptionsView.Indicator = True
      object grFirstGraph: TcxGridColumn
        Caption = 'First Graph'
        PropertiesClassName = 'TcxComboBoxProperties'
        Properties.DropDownListStyle = lsFixedList
        HeaderAlignmentHorz = taCenter
        MinWidth = 60
        Options.Filtering = False
        Options.Grouping = False
        Options.Moving = False
        Options.Sorting = False
      end
      object grSecondGraph: TcxGridColumn
        Caption = 'Last Graph'
        PropertiesClassName = 'TcxComboBoxProperties'
        Properties.DropDownListStyle = lsFixedList
        HeaderAlignmentHorz = taCenter
        Options.Filtering = False
        Options.Grouping = False
        Options.Moving = False
        Options.Sorting = False
      end
      object grName: TcxGridColumn
        Caption = 'Group Name'
        PropertiesClassName = 'TcxTextEditProperties'
        HeaderAlignmentHorz = taCenter
        Options.Filtering = False
        Options.Grouping = False
        Options.Moving = False
        Options.Sorting = False
      end
      object grOptions: TcxGridColumn
        Caption = 'Options'
        DataBinding.ValueType = 'Boolean'
        PropertiesClassName = 'TcxButtonEditProperties'
        Properties.BeepOnError = True
        Properties.Buttons = <
          item
            Default = True
            Glyph.Data = {
              42070000424D420700000000000036040000280000003B0000000D0000000100
              0800000000000C03000000000000000000000001000000000000000000000000
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
              F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6
              F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
              F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6F6F6F6F6
              F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
              F6F6F6F6F6F6F6F6F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
              F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
              F6F6F6F6F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
              F6F6F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
              F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
              F6F6000000F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
              F600F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6000000
              0000F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F600F6F6
              F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F600000000000000F6
              F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F600F6F6F6F6F6F6
              F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6000000000000000000F6F6F6F6
              F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6
              F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
              F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6F6F6F6F6
              F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
              F6F6F6F6F6F6F6F6F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
              F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
              F6F6F6F6F6F6F6F6F600F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
              F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6F6
              F6F6F6F6F600}
            Kind = bkGlyph
            LeftAlignment = True
          end>
        Properties.ViewStyle = vsHideCursor
        Properties.OnButtonClick = grOptionsPropertiesButtonClick
        HeaderAlignmentHorz = taCenter
        MinWidth = 64
        Options.Filtering = False
        Options.Grouping = False
        Options.HorzSizing = False
        Options.Moving = False
        Options.Sorting = False
      end
    end
    object GroupsGridLevel1: TcxGridLevel
      GridView = GroupsGridTableView
    end
  end
end
