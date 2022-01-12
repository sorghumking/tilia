object SumsForm: TSumsForm
  Left = 405
  Top = 270
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Sums'
  ClientHeight = 489
  ClientWidth = 521
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  OnDeactivate = FormDeactivate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel6: TPanel
    Left = 80
    Top = 336
    Width = 313
    Height = 24
    BevelOuter = bvNone
    TabOrder = 12
    Visible = False
    object Image6: TImage
      Left = 4
      Top = 4
      Width = 19
      Height = 20
      Picture.Data = {
        07544269746D617072010000424D720100000000000076000000280000001500
        0000150000000100040000000000FC0000000000000000000000100000000000
        0000000000000000800000800000008080008000000080008000808000008080
        8000C0C0C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFF
        FF00333333333333333333333000333333333333333333333000333333333333
        3333333330003333333333333333333330003333333000000033333330003333
        33306666E03333333000333333306EEE603333333000333333306EEE60333333
        3000333333306EEE603333333000333333306EEE60333333300033300000EEEE
        60000033300033330EEEEEEEEEE603333000333330EEEEEEEE60333330003333
        330EEEEEE6033333300033333330EEEE603333333000333333330EE603333333
        30003333333330E0333333333000333333333303333333333000333333333333
        333333333000333333333333333333333000333333333333333333333000}
      Transparent = True
    end
    object Label6: TLabel
      Left = 26
      Top = 8
      Width = 290
      Height = 13
      Caption = 'Repeat until all sums entered, then click the <Next> button.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
  end
  object SumsGrid: TcxGrid
    Left = 16
    Top = 32
    Width = 489
    Height = 129
    TabOrder = 19
    LookAndFeel.NativeStyle = False
    LookAndFeel.SkinName = 'Lilian'
    object SumsGridTableView: TcxGridTableView
      Navigator.Buttons.CustomButtons = <>
      Navigator.Buttons.Insert.Visible = False
      Navigator.Buttons.Delete.Visible = False
      Navigator.Buttons.Edit.Visible = False
      Navigator.Buttons.Post.Visible = False
      Navigator.Buttons.Cancel.Visible = False
      Navigator.Buttons.Refresh.Visible = False
      Navigator.Buttons.SaveBookmark.Visible = False
      Navigator.Buttons.GotoBookmark.Visible = False
      Navigator.Buttons.Filter.Visible = False
      Navigator.Visible = True
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.AlwaysShowEditor = True
      OptionsBehavior.FocusCellOnTab = True
      OptionsBehavior.FocusFirstCellOnNewRecord = True
      OptionsBehavior.GoToNextCellOnEnter = True
      OptionsData.Deleting = False
      OptionsData.Inserting = False
      OptionsSelection.InvertSelect = False
      OptionsView.ShowEditButtons = gsebAlways
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      OptionsView.Indicator = True
      object suCode: TcxGridColumn
        Caption = 'Code'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.Alignment.Horz = taCenter
        HeaderAlignmentHorz = taCenter
        Options.Editing = False
        Options.Filtering = False
        Options.Moving = False
      end
      object suName: TcxGridColumn
        Caption = 'Name'
        PropertiesClassName = 'TcxTextEditProperties'
        HeaderAlignmentHorz = taCenter
        Options.Filtering = False
        Options.Moving = False
        Width = 231
      end
      object suBase: TcxGridColumn
        Caption = 'Base'
        PropertiesClassName = 'TcxComboBoxProperties'
        Properties.Alignment.Horz = taCenter
        Properties.DropDownListStyle = lsEditFixedList
        Properties.Items.Strings = (
          'None')
        HeaderAlignmentHorz = taCenter
        Options.Filtering = False
        Options.Grouping = False
        Options.Moving = False
        Width = 74
      end
      object suPercent: TcxGridColumn
        Caption = 'Percent'
        DataBinding.ValueType = 'Boolean'
        PropertiesClassName = 'TcxCheckBoxProperties'
        HeaderAlignmentHorz = taCenter
        Options.Filtering = False
        Options.Moving = False
        Width = 54
      end
      object suSkip: TcxGridColumn
        Caption = 'Skip'
        DataBinding.ValueType = 'Boolean'
        PropertiesClassName = 'TcxCheckBoxProperties'
        HeaderAlignmentHorz = taCenter
        Options.Filtering = False
        Options.Moving = False
        Options.Sorting = False
        Width = 54
      end
    end
    object SumsGridLevel1: TcxGridLevel
      GridView = SumsGridTableView
    end
  end
  object SuperSumsGrid: TcxGrid
    Left = 16
    Top = 192
    Width = 489
    Height = 145
    TabOrder = 1
    LookAndFeel.NativeStyle = False
    LookAndFeel.SkinName = 'Lilian'
    object SuperSumsGridTableView: TcxGridTableView
      Navigator.Buttons.OnButtonClick = SuperSumsGridTableViewNavigatorButtonsButtonClick
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
      OptionsBehavior.FocusCellOnTab = True
      OptionsBehavior.FocusFirstCellOnNewRecord = True
      OptionsBehavior.GoToNextCellOnEnter = True
      OptionsBehavior.NavigatorHints = True
      OptionsBehavior.FocusCellOnCycle = True
      OptionsCustomize.ColumnMoving = False
      OptionsData.Appending = True
      OptionsData.DeletingConfirmation = False
      OptionsSelection.InvertSelect = False
      OptionsView.ShowEditButtons = gsebAlways
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      OptionsView.Indicator = True
      object ssCode: TcxGridColumn
        Caption = 'Code'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.OnEditValueChanged = ssCodePropertiesEditValueChanged
        HeaderAlignmentHorz = taCenter
        Options.Filtering = False
        Options.Moving = False
        Width = 72
      end
      object ssName: TcxGridColumn
        Caption = 'Name'
        PropertiesClassName = 'TcxTextEditProperties'
        HeaderAlignmentHorz = taCenter
        Options.Filtering = False
        Options.Moving = False
        Width = 215
      end
      object ssInclude: TcxGridColumn
        Caption = 'Include Groups'
        PropertiesClassName = 'TcxCheckComboBoxProperties'
        Properties.Items = <>
        HeaderAlignmentHorz = taCenter
        Options.Filtering = False
        Options.Moving = False
        Options.Sorting = False
        Width = 188
      end
    end
    object SuperSumsGridLevel1: TcxGridLevel
      GridView = SuperSumsGridTableView
    end
  end
  object Button1: TButton
    Left = 16
    Top = 448
    Width = 75
    Height = 25
    Caption = '&Ok'
    ModalResult = 1
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 104
    Top = 448
    Width = 75
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 3
  end
  object Button3: TButton
    Left = 192
    Top = 448
    Width = 75
    Height = 25
    Caption = '&Help'
    TabOrder = 4
  end
  object Button4: TButton
    Left = 16
    Top = 408
    Width = 75
    Height = 25
    Caption = 'Guide Me...'
    TabOrder = 5
    OnClick = Button4Click
  end
  object Panel1: TPanel
    Left = 90
    Top = 6
    Width = 175
    Height = 24
    BevelOuter = bvNone
    TabOrder = 6
    Visible = False
    object Image1: TImage
      Left = 4
      Top = 4
      Width = 19
      Height = 20
      Picture.Data = {
        07544269746D617072010000424D720100000000000076000000280000001500
        0000150000000100040000000000FC0000000000000000000000100000000000
        0000000000000000800000800000008080008000000080008000808000008080
        8000C0C0C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFF
        FF00333333333333333333333000333333333333333333333000333333333333
        3333333330003333333333033333333330003333333330E03333333330003333
        333306EE033333333000333333306EEEE0333333300033333306EEEEEE033333
        30003333306EEEEEEEE033333000333306EEEEEEEEEE03333000333000006EEE
        E00000333000333333306EEE603333333000333333306EEE6033333330003333
        33306EEE603333333000333333306EEE60333333300033333330E66660333333
        3000333333300000003333333000333333333333333333333000333333333333
        333333333000333333333333333333333000333333333333333333333000}
      Transparent = True
    end
    object Label1: TLabel
      Left = 26
      Top = 8
      Width = 141
      Height = 14
      Caption = 'Enter names for group codes'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
  end
  object Button5: TButton
    Left = 104
    Top = 408
    Width = 75
    Height = 25
    Caption = 'Next'
    TabOrder = 7
    Visible = False
    OnClick = Button5Click
  end
  object Panel2: TPanel
    Left = 38
    Top = 166
    Width = 139
    Height = 24
    BevelOuter = bvNone
    TabOrder = 8
    Visible = False
    object Image2: TImage
      Left = 4
      Top = 4
      Width = 19
      Height = 20
      Picture.Data = {
        07544269746D617072010000424D720100000000000076000000280000001500
        0000150000000100040000000000FC0000000000000000000000100000000000
        0000000000000000800000800000008080008000000080008000808000008080
        8000C0C0C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFF
        FF00333333333333333333333000333333333333333333333000333333333333
        3333333330003333333333033333333330003333333330E03333333330003333
        333306EE033333333000333333306EEEE0333333300033333306EEEEEE033333
        30003333306EEEEEEEE033333000333306EEEEEEEEEE03333000333000006EEE
        E00000333000333333306EEE603333333000333333306EEE6033333330003333
        33306EEE603333333000333333306EEE60333333300033333330E66660333333
        3000333333300000003333333000333333333333333333333000333333333333
        333333333000333333333333333333333000333333333333333333333000}
      Transparent = True
    end
    object Label2: TLabel
      Left = 26
      Top = 8
      Width = 113
      Height = 13
      Caption = 'Enter code for first sum'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
  end
  object Panel3: TPanel
    Left = 94
    Top = 166
    Width = 139
    Height = 24
    BevelOuter = bvNone
    TabOrder = 9
    Visible = False
    object Image3: TImage
      Left = 4
      Top = 4
      Width = 19
      Height = 20
      Picture.Data = {
        07544269746D617072010000424D720100000000000076000000280000001500
        0000150000000100040000000000FC0000000000000000000000100000000000
        0000000000000000800000800000008080008000000080008000808000008080
        8000C0C0C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFF
        FF00333333333333333333333000333333333333333333333000333333333333
        3333333330003333333333033333333330003333333330E03333333330003333
        333306EE033333333000333333306EEEE0333333300033333306EEEEEE033333
        30003333306EEEEEEEE033333000333306EEEEEEEEEE03333000333000006EEE
        E00000333000333333306EEE603333333000333333306EEE6033333330003333
        33306EEE603333333000333333306EEE60333333300033333330E66660333333
        3000333333300000003333333000333333333333333333333000333333333333
        333333333000333333333333333333333000333333333333333333333000}
      Transparent = True
    end
    object Label3: TLabel
      Left = 26
      Top = 8
      Width = 116
      Height = 13
      Caption = 'Enter name for first sum'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
  end
  object Panel4: TPanel
    Left = 208
    Top = 166
    Width = 153
    Height = 24
    BevelOuter = bvNone
    TabOrder = 10
    Visible = False
    object Image4: TImage
      Left = 124
      Top = 4
      Width = 19
      Height = 20
      Picture.Data = {
        07544269746D617072010000424D720100000000000076000000280000001500
        0000150000000100040000000000FC0000000000000000000000100000000000
        0000000000000000800000800000008080008000000080008000808000008080
        8000C0C0C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFF
        FF00333333333333333333333000333333333333333333333000333333333333
        3333333330003333333333033333333330003333333330E03333333330003333
        333306EE033333333000333333306EEEE0333333300033333306EEEEEE033333
        30003333306EEEEEEEE033333000333306EEEEEEEEEE03333000333000006EEE
        E00000333000333333306EEE603333333000333333306EEE6033333330003333
        33306EEE603333333000333333306EEE60333333300033333330E66660333333
        3000333333300000003333333000333333333333333333333000333333333333
        333333333000333333333333333333333000333333333333333333333000}
      Transparent = True
    end
    object Label4: TLabel
      Left = 2
      Top = 8
      Width = 120
      Height = 13
      Caption = 'Select groups in first sum'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
  end
  object Panel5: TPanel
    Left = 128
    Top = 336
    Width = 113
    Height = 24
    BevelOuter = bvNone
    TabOrder = 11
    Visible = False
    object Image5: TImage
      Left = 4
      Top = 4
      Width = 19
      Height = 20
      Picture.Data = {
        07544269746D617072010000424D720100000000000076000000280000001500
        0000150000000100040000000000FC0000000000000000000000100000000000
        0000000000000000800000800000008080008000000080008000808000008080
        8000C0C0C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFF
        FF00333333333333333333333000333333333333333333333000333333333333
        3333333330003333333333333333333330003333333000000033333330003333
        33306666E03333333000333333306EEE603333333000333333306EEE60333333
        3000333333306EEE603333333000333333306EEE60333333300033300000EEEE
        60000033300033330EEEEEEEEEE603333000333330EEEEEEEE60333330003333
        330EEEEEE6033333300033333330EEEE603333333000333333330EE603333333
        30003333333330E0333333333000333333333303333333333000333333333333
        333333333000333333333333333333333000333333333333333333333000}
      Transparent = True
    end
    object Label5: TLabel
      Left = 26
      Top = 8
      Width = 80
      Height = 13
      Caption = 'Click post button'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
  end
  object Panel7: TPanel
    Left = 58
    Top = 6
    Width = 313
    Height = 24
    BevelOuter = bvNone
    TabOrder = 13
    Visible = False
    object Image7: TImage
      Left = 284
      Top = 4
      Width = 19
      Height = 20
      Picture.Data = {
        07544269746D617072010000424D720100000000000076000000280000001500
        0000150000000100040000000000FC0000000000000000000000100000000000
        0000000000000000800000800000008080008000000080008000808000008080
        8000C0C0C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFF
        FF00333333333333333333333000333333333333333333333000333333333333
        3333333330003333333333033333333330003333333330E03333333330003333
        333306EE033333333000333333306EEEE0333333300033333306EEEEEE033333
        30003333306EEEEEEEE033333000333306EEEEEEEEEE03333000333000006EEE
        E00000333000333333306EEE603333333000333333306EEE6033333330003333
        33306EEE603333333000333333306EEE60333333300033333330E66660333333
        3000333333300000003333333000333333333333333333333000333333333333
        333333333000333333333333333333333000333333333333333333333000}
      Transparent = True
    end
    object Label7: TLabel
      Left = 2
      Top = 8
      Width = 280
      Height = 13
      Caption = 'Select the sums upon which percentages should be based.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
  end
  object Panel8: TPanel
    Left = 128
    Top = 6
    Width = 299
    Height = 24
    BevelOuter = bvNone
    TabOrder = 14
    Visible = False
    object Image8: TImage
      Left = 276
      Top = 4
      Width = 19
      Height = 20
      Picture.Data = {
        07544269746D617072010000424D720100000000000076000000280000001500
        0000150000000100040000000000FC0000000000000000000000100000000000
        0000000000000000800000800000008080008000000080008000808000008080
        8000C0C0C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFF
        FF00333333333333333333333000333333333333333333333000333333333333
        3333333330003333333333033333333330003333333330E03333333330003333
        333306EE033333333000333333306EEEE0333333300033333306EEEEEE033333
        30003333306EEEEEEEE033333000333306EEEEEEEEEE03333000333000006EEE
        E00000333000333333306EEE603333333000333333306EEE6033333330003333
        33306EEE603333333000333333306EEE60333333300033333330E66660333333
        3000333333300000003333333000333333333333333333333000333333333333
        333333333000333333333333333333333000333333333333333333333000}
      Transparent = True
    end
    object Label8: TLabel
      Left = 2
      Top = 8
      Width = 274
      Height = 13
      Caption = 'Check box if percentages should be calculated for group.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
  end
  object Panel10: TPanel
    Left = 260
    Top = 6
    Width = 225
    Height = 24
    BevelOuter = bvNone
    TabOrder = 0
    Visible = False
    object Image10: TImage
      Left = 196
      Top = 4
      Width = 19
      Height = 20
      Picture.Data = {
        07544269746D617072010000424D720100000000000076000000280000001500
        0000150000000100040000000000FC0000000000000000000000100000000000
        0000000000000000800000800000008080008000000080008000808000008080
        8000C0C0C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFF
        FF00333333333333333333333000333333333333333333333000333333333333
        3333333330003333333333033333333330003333333330E03333333330003333
        333306EE033333333000333333306EEEE0333333300033333306EEEEEE033333
        30003333306EEEEEEEE033333000333306EEEEEEEEEE03333000333000006EEE
        E00000333000333333306EEE603333333000333333306EEE6033333330003333
        33306EEE603333333000333333306EEE60333333300033333330E66660333333
        3000333333300000003333333000333333333333333333333000333333333333
        333333333000333333333333333333333000333333333333333333333000}
      Transparent = True
    end
    object Label10: TLabel
      Left = 8
      Top = 8
      Width = 184
      Height = 13
      Alignment = taRightJustify
      Caption = 'Click Skip to not include group in a sum'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
  end
  object Button6: TButton
    Left = 192
    Top = 408
    Width = 75
    Height = 25
    Caption = 'Previous'
    TabOrder = 16
    Visible = False
    OnClick = Button6Click
  end
  object Panel9: TPanel
    Left = 38
    Top = 422
    Width = 313
    Height = 24
    BevelOuter = bvNone
    TabOrder = 15
    Visible = False
    object Image9: TImage
      Left = 4
      Top = 4
      Width = 19
      Height = 20
      Picture.Data = {
        07544269746D617072010000424D720100000000000076000000280000001500
        0000150000000100040000000000FC0000000000000000000000100000000000
        0000000000000000800000800000008080008000000080008000808000008080
        8000C0C0C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFF
        FF00333333333333333333333000333333333333333333333000333333333333
        3333333330003333333333033333333330003333333330E03333333330003333
        333306EE033333333000333333306EEEE0333333300033333306EEEEEE033333
        30003333306EEEEEEEE033333000333306EEEEEEEEEE03333000333000006EEE
        E00000333000333333306EEE603333333000333333306EEE6033333330003333
        33306EEE603333333000333333306EEE60333333300033333330E66660333333
        3000333333300000003333333000333333333333333333333000333333333333
        333333333000333333333333333333333000333333333333333333333000}
      Transparent = True
    end
    object Label9: TLabel
      Left = 26
      Top = 8
      Width = 281
      Height = 13
      Caption = 'Finished! Click <Ok> button to enter sums in spreadsheet.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
  end
  object RadioGroup1: TRadioGroup
    Left = 384
    Top = 363
    Width = 121
    Height = 65
    Caption = 'Calculate Sums As...'
    ItemIndex = 0
    Items.Strings = (
      'Values'
      'Formulas')
    TabOrder = 17
    OnClick = RadioGroup1Click
  end
  object Button7: TButton
    Left = 16
    Top = 368
    Width = 73
    Height = 25
    Caption = 'Default Sums'
    TabOrder = 18
    OnClick = Button7Click
  end
end
