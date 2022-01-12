object SubmissionForm: TSubmissionForm
  Left = 375
  Top = 453
  BorderStyle = bsDialog
  ClientHeight = 411
  ClientWidth = 335
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object SpeedButton1: TSpeedButton
    Left = 8
    Top = 8
    Width = 160
    Height = 25
    GroupIndex = 1
    Down = True
    OnClick = SpeedButton1Click
  end
  object SpeedButton2: TSpeedButton
    Left = 168
    Top = 8
    Width = 160
    Height = 25
    GroupIndex = 1
    Caption = 'Loss-on-ignition'
    OnClick = SpeedButton2Click
  end
  object Button1: TButton
    Left = 84
    Top = 376
    Width = 73
    Height = 25
    Caption = 'Ok'
    ModalResult = 1
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 172
    Top = 376
    Width = 73
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
    OnClick = Button2Click
  end
  object Panel2: TPanel
    Left = 8
    Top = 40
    Width = 320
    Height = 297
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    object SubmissionGrid: TcxGrid
      Left = 2
      Top = 2
      Width = 316
      Height = 293
      Align = alClient
      TabOrder = 0
      LookAndFeel.NativeStyle = False
      LookAndFeel.SkinName = 'Lilian'
      object SubmissionGridCardView1: TcxGridCardView
        Navigator.Buttons.CustomButtons = <>
        Navigator.Buttons.PriorPage.Enabled = False
        Navigator.Buttons.Prior.Visible = True
        Navigator.Buttons.Insert.Visible = True
        Navigator.Buttons.Edit.Visible = False
        Navigator.Buttons.Cancel.Visible = True
        Navigator.Buttons.Refresh.Visible = False
        Navigator.Buttons.SaveBookmark.Enabled = False
        Navigator.Buttons.SaveBookmark.Visible = False
        Navigator.Buttons.GotoBookmark.Visible = False
        Navigator.Buttons.Filter.Visible = False
        Navigator.Visible = True
        OnFocusedItemChanged = SubmissionGridCardView1FocusedItemChanged
        OnFocusedRecordChanged = SubmissionGridCardView1FocusedRecordChanged
        DataController.Options = [dcoCaseInsensitive, dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoSortByDisplayText]
        DataController.Summary.DefaultGroupSummaryItems = <>
        DataController.Summary.FooterSummaryItems = <>
        DataController.Summary.SummaryGroups = <>
        DataController.Data = {
          940000000F00000044617461436F6E74726F6C6C657231050000001200000054
          6378537472696E6756616C75655479706511000000546378466C6F617456616C
          75655479706512000000546378537472696E6756616C75655479706512000000
          546378537472696E6756616C75655479706512000000546378537472696E6756
          616C75655479706501000000445855464D54000101010101}
        LayoutDirection = ldVertical
        OptionsBehavior.AlwaysShowEditor = True
        OptionsBehavior.FocusCellOnTab = True
        OptionsBehavior.FocusFirstCellOnNewRecord = True
        OptionsBehavior.GoToNextCellOnEnter = True
        OptionsBehavior.NavigatorHints = True
        OptionsData.Appending = True
        OptionsView.ShowEditButtons = gsebForFocusedRecord
        OptionsView.CardIndent = 7
        OptionsView.CardWidth = 289
        Styles.Background = cxStyle7
        Styles.Content = cxStyle4
        Styles.Selection = cxStyle9
        Styles.CardBorder = cxStyle12
        Styles.RowCaption = cxStyle3
        object suSubmittedForm: TcxGridCardViewRow
          Caption = 'Data form'
          PropertiesClassName = 'TcxComboBoxProperties'
          Properties.Items.Strings = (
            'Raw counts'
            'Raw percentages'
            'Digitized Counts'
            'Digitized Percentages')
          Options.Filtering = False
          Options.FilteringMRUItemsList = False
          Options.Moving = False
          Position.BeginsLayer = True
          Styles.Content = cxStyle17
          Styles.Caption = cxStyle3
        end
        object suSubmissionDate: TcxGridCardViewRow
          Caption = 'Submission date'
          DataBinding.ValueType = 'Float'
          PropertiesClassName = 'TcxDateEditProperties'
          Options.Filtering = False
          Options.Moving = False
          Position.BeginsLayer = True
          SortIndex = 0
          SortOrder = soAscending
          Styles.Content = cxStyle17
          Styles.Caption = cxStyle3
        end
        object suSubmissionType: TcxGridCardViewRow
          Caption = 'Submission type'
          PropertiesClassName = 'TcxComboBoxProperties'
          Properties.DropDownListStyle = lsEditFixedList
          Properties.Items.Strings = (
            'Integrative compilation'
            'Integrative recompilation'
            'Primary submission'
            'Secondary submission'
            'Simple compilation'
            'System integrative compilation'
            'System integrative recompilation')
          Options.Filtering = False
          Options.Moving = False
          Position.BeginsLayer = True
          Styles.Content = cxStyle17
          Styles.Caption = cxStyle3
        end
        object suSubmitters: TcxGridCardViewRow
          Caption = 'Submitters'
          PropertiesClassName = 'TcxCheckComboBoxProperties'
          Properties.Items = <>
          Properties.OnEditValueToStates = suSubmittersPropertiesEditValueToStates
          Properties.OnStatesToEditValue = suSubmittersPropertiesStatesToEditValue
          OnGetDisplayText = suSubmittersGetDisplayText
          Options.Filtering = False
          Options.Moving = False
          Position.BeginsLayer = True
          Styles.Content = cxStyle17
          Styles.Caption = cxStyle3
        end
        object suNotes: TcxGridCardViewRow
          Caption = 'Notes'
          PropertiesClassName = 'TcxMemoProperties'
          Properties.VisibleLineCount = 3
          Options.Filtering = False
          Options.Moving = False
          Position.BeginsLayer = True
          Styles.Content = cxStyle17
          Styles.Caption = cxStyle3
        end
      end
      object SubmissionGridLevel1: TcxGridLevel
        Caption = 'shit'
        GridView = SubmissionGridCardView1
      end
    end
  end
  object Panel1: TPanel
    Left = 8
    Top = 336
    Width = 320
    Height = 29
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 3
    object Label1: TLabel
      Left = 206
      Top = 8
      Width = 97
      Height = 13
      Caption = 'Archived Submission'
    end
    object SpeedButton3: TSpeedButton
      Left = 4
      Top = 4
      Width = 25
      Height = 22
      Hint = 'Permit editing of archived submissions'
      AllowAllUp = True
      GroupIndex = 1
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333000000
        000033333377777777773333330FFFFFFFF03FF3FF7FF33F3FF700300000FF0F
        00F077F777773F737737E00BFBFB0FFFFFF07773333F7F3333F7E0BFBF000FFF
        F0F077F3337773F3F737E0FBFBFBF0F00FF077F3333FF7F77F37E0BFBF00000B
        0FF077F3337777737337E0FBFBFBFBF0FFF077F33FFFFFF73337E0BF0000000F
        FFF077FF777777733FF7000BFB00B0FF00F07773FF77373377373330000B0FFF
        FFF03337777373333FF7333330B0FFFF00003333373733FF777733330B0FF00F
        0FF03333737F37737F373330B00FFFFF0F033337F77F33337F733309030FFFFF
        00333377737FFFFF773333303300000003333337337777777333}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = SpeedButton3Click
    end
    object Button3: TButton
      Left = 32
      Top = 4
      Width = 77
      Height = 22
      Caption = 'New Contact'
      TabOrder = 0
      Visible = False
      OnClick = Button3Click
    end
  end
  object cxStyleRepository1: TcxStyleRepository
    Left = 8
    Top = 368
    PixelsPerInch = 96
    object cxStyle1: TcxStyle
    end
    object cxStyle3: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 13160660
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle4: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 13160660
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clSilver
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle5: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 13160660
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle6: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clGray
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = 13160660
    end
    object cxStyle7: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 10841658
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle8: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clSkyBlue
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle9: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 6956042
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clWhite
    end
    object cxStyle10: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 13160660
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle11: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = 6956042
    end
    object cxStyle12: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 6956042
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      TextColor = clWhite
    end
    object cxStyle2: TcxStyle
    end
    object cxStyle13: TcxStyle
      AssignedValues = [svColor]
      Color = 15451300
    end
    object cxStyle14: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 16247513
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle15: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 16247513
      TextColor = clBlack
    end
    object cxStyle16: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 16247513
      TextColor = clBlack
    end
    object cxStyle17: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = clWhite
      TextColor = clBlack
    end
    object cxStyle18: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 14811135
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      TextColor = clNavy
    end
    object cxStyle19: TcxStyle
      AssignedValues = [svColor]
      Color = 14872561
    end
    object cxStyle20: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 4707838
      TextColor = clBlack
    end
    object cxStyle21: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 12937777
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle22: TcxStyle
      AssignedValues = [svColor]
      Color = 15451300
    end
    object cxStyle23: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 4707838
      TextColor = clBlack
    end
    object cxStyle24: TcxStyle
      AssignedValues = [svColor]
      Color = 13160660
    end
    object cxStyle25: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 14811135
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      TextColor = clNavy
    end
    object cxStyle26: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 12937777
      TextColor = clWhite
    end
    object cxStyle27: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle28: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 10542814
      TextColor = clBlack
    end
    object cxStyle29: TcxStyle
      AssignedValues = [svColor, svTextColor]
      Color = 13692654
      TextColor = clBlack
    end
    object cxStyle30: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 10542814
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clBlack
    end
    object cxStyle31: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 4308156
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clWhite
    end
    object cxStyle32: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 1916928
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle33: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 10542814
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle34: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clOlive
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clWhite
    end
    object cxStyle35: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 10542814
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = [fsBold]
      TextColor = clBlack
    end
    object cxStyle36: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clOlive
    end
    object cxStyle37: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = clOlive
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Microsoft Sans Serif'
      Font.Style = []
      TextColor = clWhite
    end
    object GridTableViewStyleSheetWindowsStandard: TcxGridTableViewStyleSheet
      Caption = 'Windows Standard'
      Styles.ContentEven = cxStyle3
      Styles.ContentOdd = cxStyle4
      Styles.Inactive = cxStyle9
      Styles.Selection = cxStyle12
      Styles.Footer = cxStyle5
      Styles.Group = cxStyle6
      Styles.GroupByBox = cxStyle7
      Styles.Header = cxStyle8
      Styles.Indicator = cxStyle10
      Styles.Preview = cxStyle11
      BuiltIn = True
    end
    object GridTableViewStyleSheetDevExpress: TcxGridTableViewStyleSheet
      Caption = 'DevExpress'
      Styles.Background = cxStyle13
      Styles.Content = cxStyle14
      Styles.ContentEven = cxStyle15
      Styles.ContentOdd = cxStyle16
      Styles.FilterBox = cxStyle17
      Styles.Inactive = cxStyle22
      Styles.IncSearch = cxStyle23
      Styles.Selection = cxStyle26
      Styles.Footer = cxStyle18
      Styles.Group = cxStyle19
      Styles.GroupByBox = cxStyle20
      Styles.Header = cxStyle21
      Styles.Indicator = cxStyle24
      Styles.Preview = cxStyle25
      BuiltIn = True
    end
    object GridTableViewStyleSheetWheat: TcxGridTableViewStyleSheet
      Caption = 'Wheat'
      Styles.Content = cxStyle27
      Styles.ContentEven = cxStyle28
      Styles.ContentOdd = cxStyle29
      Styles.Inactive = cxStyle34
      Styles.Selection = cxStyle37
      Styles.Footer = cxStyle30
      Styles.Group = cxStyle31
      Styles.GroupByBox = cxStyle32
      Styles.Header = cxStyle33
      Styles.Indicator = cxStyle35
      Styles.Preview = cxStyle36
      BuiltIn = True
    end
  end
end
