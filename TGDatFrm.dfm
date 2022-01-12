object DatesForm: TDatesForm
  Left = 429
  Top = 232
  HelpContext = 98
  BorderIcons = [biSystemMenu, biHelp]
  BorderStyle = bsDialog
  Caption = 'Dates'
  ClientHeight = 300
  ClientWidth = 603
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
  OnCreate = FormCreate
  OnDeactivate = FormDeactivate
  OnHelp = FormHelp
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 124
    Top = 232
    Width = 29
    Height = 13
    Caption = 'Color:'
    FocusControl = ColorBox1
  end
  object RadioGroup1: TRadioGroup
    Left = 12
    Top = 232
    Width = 93
    Height = 57
    Hint = 'Position of dates on diagram'
    Caption = 'Diagram Position'
    Items.Strings = (
      'Left'
      'Right')
    TabOrder = 0
  end
  object GroupBox1: TGroupBox
    Left = 368
    Top = 27
    Width = 225
    Height = 154
    Caption = 'Label'
    TabOrder = 2
    object Edit1: TEdit
      Left = 8
      Top = 24
      Width = 188
      Height = 21
      Hint = 'Dates label'
      HelpContext = 100
      TabOrder = 1
    end
    object RadioGroup2: TRadioGroup
      Left = 8
      Top = 56
      Width = 105
      Height = 89
      Hint = 'Position of dates label'
      HelpContext = 101
      Caption = 'Postion'
      Items.Strings = (
        'Automatic Side'
        'Automatic Top'
        'User Defined')
      TabOrder = 2
      OnClick = RadioGroup2Click
    end
    object GroupBox2: TGroupBox
      Left = 120
      Top = 56
      Width = 97
      Height = 89
      HelpContext = 102
      Caption = 'Coordinates'
      TabOrder = 0
      object LabeledEdit1: TLabeledEdit
        Left = 40
        Top = 64
        Width = 49
        Height = 21
        Hint = 'Angle of dates label'
        HelpContext = 102
        EditLabel.Width = 27
        EditLabel.Height = 13
        EditLabel.Caption = 'Angle'
        LabelPosition = lpLeft
        TabOrder = 2
      end
      object LabeledEdit2: TLabeledEdit
        Left = 24
        Top = 16
        Width = 65
        Height = 21
        Hint = 'X-coordinate of dates label'
        HelpContext = 102
        EditLabel.Width = 6
        EditLabel.Height = 13
        EditLabel.Caption = 'X'
        LabelPosition = lpLeft
        TabOrder = 0
      end
      object LabeledEdit3: TLabeledEdit
        Left = 24
        Top = 40
        Width = 65
        Height = 21
        Hint = 'Y-coordinate of dates label'
        HelpContext = 102
        EditLabel.Width = 6
        EditLabel.Height = 13
        EditLabel.Caption = 'Y'
        LabelPosition = lpLeft
        TabOrder = 1
      end
    end
    object cxButton6: TcxButton
      Left = 195
      Top = 24
      Width = 21
      Height = 21
      LookAndFeel.Kind = lfOffice11
      OptionsImage.Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        04000000000080000000CE0E0000D80E00001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        7777777744444444444477777777777777777777444447774444777777447777
        7447777777744777744777777777444444477777777774477447707770777744
        7447708780777774444778000877777744477707077777777447770707777777
        7777778087777777777777707777777777777777777777777777}
      TabOrder = 3
      OnClick = cxButton6Click
    end
  end
  object ColorBox1: TColorBox
    Left = 124
    Top = 248
    Width = 125
    Height = 22
    Hint = 'Dates color'
    HelpContext = 7
    DefaultColorColor = clGray
    Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
    TabOrder = 1
  end
  object DatesGrid: TcxGrid
    Left = 12
    Top = 32
    Width = 345
    Height = 182
    Hint = 'Dates data'
    HelpContext = 98
    TabOrder = 3
    LookAndFeel.Kind = lfUltraFlat
    LookAndFeel.NativeStyle = False
    LookAndFeel.SkinName = 'Lilian'
    object DatesGridTableView: TcxGridTableView
      Navigator.Buttons.CustomButtons = <>
      Navigator.Buttons.Edit.Visible = False
      Navigator.Buttons.Post.Visible = True
      Navigator.Buttons.Refresh.Visible = False
      Navigator.Buttons.SaveBookmark.Visible = False
      Navigator.Buttons.GotoBookmark.Visible = False
      Navigator.Buttons.Filter.Visible = False
      Navigator.Visible = True
      OnEditKeyUp = DatesGridTableViewEditKeyUp
      OnFocusedItemChanged = DatesGridTableViewFocusedItemChanged
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
      OptionsData.DeletingConfirmation = False
      OptionsSelection.InvertSelect = False
      OptionsView.CellEndEllipsis = True
      OptionsView.ShowEditButtons = gsebAlways
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      OptionsView.HeaderEndEllipsis = True
      OptionsView.Indicator = True
      object daTopDepth: TcxGridColumn
        Caption = 'Top Depth'
        DataBinding.ValueType = 'Float'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.Alignment.Horz = taRightJustify
        Properties.UseLeftAlignmentOnEditing = False
        Properties.ValidateOnEnter = True
        Properties.OnValidate = daTopDepthPropertiesValidate
        HeaderAlignmentHorz = taCenter
        MinWidth = 70
        Options.Filtering = False
        Options.Grouping = False
        Options.Moving = False
        Width = 82
      end
      object daBottomDepth: TcxGridColumn
        Caption = 'Bottom Depth'
        DataBinding.ValueType = 'Float'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.Alignment.Horz = taRightJustify
        Properties.BeepOnError = True
        Properties.UseLeftAlignmentOnEditing = False
        Properties.ValidateOnEnter = True
        Properties.OnValidate = daBottomDepthPropertiesValidate
        HeaderAlignmentHorz = taCenter
        MinWidth = 70
        Options.Filtering = False
        Options.Grouping = False
        Options.Moving = False
        Options.Sorting = False
        Width = 82
      end
      object daDate: TcxGridColumn
        Caption = 'Date'
        PropertiesClassName = 'TcxTextEditProperties'
        OnGetDisplayText = daDateGetDisplayText
        HeaderAlignmentHorz = taCenter
        MinWidth = 60
        Options.Filtering = False
        Options.Grouping = False
        Options.Moving = False
        Options.Sorting = False
        Width = 100
      end
      object daOffset: TcxGridColumn
        Caption = 'Offset'
        DataBinding.ValueType = 'Float'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.Alignment.Horz = taRightJustify
        Properties.BeepOnError = True
        Properties.UseLeftAlignmentOnEditing = False
        Properties.ValidateOnEnter = True
        Properties.OnValidate = daOffsetPropertiesValidate
        HeaderAlignmentHorz = taCenter
        MinWidth = 60
        Options.Filtering = False
        Options.Grouping = False
        Options.Moving = False
        Options.Sorting = False
        Width = 79
      end
    end
    object DatesGridLevel1: TcxGridLevel
      GridView = DatesGridTableView
    end
  end
  object cxButton1: TcxButton
    Left = 368
    Top = 264
    Width = 65
    Height = 25
    Caption = '&Ok'
    LookAndFeel.Kind = lfOffice11
    LookAndFeel.NativeStyle = False
    ModalResult = 1
    TabOrder = 4
    OnClick = cxButton1Click
  end
  object cxButton2: TcxButton
    Left = 448
    Top = 264
    Width = 65
    Height = 25
    Caption = '&Cancel'
    LookAndFeel.Kind = lfOffice11
    LookAndFeel.NativeStyle = False
    ModalResult = 2
    TabOrder = 5
  end
  object cxButton3: TcxButton
    Left = 528
    Top = 264
    Width = 65
    Height = 25
    Caption = '&Help'
    LookAndFeel.Kind = lfOffice11
    LookAndFeel.NativeStyle = False
    TabOrder = 6
    OnClick = cxButton3Click
  end
  object cxButton4: TcxButton
    Left = 184
    Top = 8
    Width = 21
    Height = 21
    Caption = #177
    LookAndFeel.Kind = lfOffice11
    TabOrder = 7
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    OnClick = cxButton4Click
  end
  object cxButton5: TcxButton
    Left = 368
    Top = 189
    Width = 81
    Height = 25
    Caption = 'Date Font'
    LookAndFeel.Kind = lfOffice11
    OptionsImage.Glyph.Data = {
      F6000000424DF600000000000000760000002800000010000000100000000100
      04000000000080000000CE0E0000D80E00001000000000000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
      7777777744444444444477777777777777777777444447774444777777447777
      7447777777744777744777777777444444477777777774477447707770777744
      7447708780777774444778000877777744477707077777777447770707777777
      7777778087777777777777707777777777777777777777777777}
    TabOrder = 8
    OnClick = cxButton5Click
  end
end
