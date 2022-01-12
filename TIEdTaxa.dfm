object EditTaxaForm: TEditTaxaForm
  Left = 407
  Top = 222
  BorderStyle = bsDialog
  Caption = 'Edit Taxa'
  ClientHeight = 415
  ClientWidth = 577
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  OnDestroy = FormDestroy
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object ToolBar1: TToolBar
    Left = 0
    Top = 37
    Width = 577
    Height = 29
    Caption = 'ToolBar1'
    Images = cxImageList1
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    object ToolButton3: TToolButton
      Left = 0
      Top = 0
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 2
      Style = tbsSeparator
    end
    object cxButton4: TcxButton
      Left = 8
      Top = 0
      Width = 89
      Height = 22
      Caption = 'Search Options...'
      DropDownMenu = PopupMenu1
      LookAndFeel.Kind = lfFlat
      TabOrder = 1
    end
    object ToolButton2: TToolButton
      Left = 97
      Top = 0
      Hint = 'Search'
      Caption = 'ToolButton2'
      ImageIndex = 3
      OnClick = ToolButton2Click
    end
    object ToolButton4: TToolButton
      Left = 120
      Top = 0
      Hint = 'Search again'
      Caption = 'ToolButton4'
      ImageIndex = 4
      OnClick = ToolButton4Click
    end
    object cxComboBox1: TcxComboBox
      Left = 143
      Top = 0
      Hint = 'Search string'
      Properties.ImmediateDropDownWhenKeyPressed = False
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 0
      Width = 344
    end
    object SpeedButton1: TSpeedButton
      Left = 487
      Top = 0
      Width = 72
      Height = 22
      AllowAllUp = True
      Caption = 'Edit Groups'
      Flat = True
      Transparent = False
      OnClick = SpeedButton1Click
    end
  end
  object TaxaGrid: TcxGrid
    Left = 0
    Top = 66
    Width = 577
    Height = 316
    Align = alClient
    BevelKind = bkFlat
    TabOrder = 0
    LookAndFeel.NativeStyle = False
    LookAndFeel.SkinName = 'Lilian'
    object TaxaGridTableView1: TcxGridTableView
      Navigator.Buttons.CustomButtons = <>
      Navigator.Buttons.First.Visible = True
      Navigator.Buttons.Prior.Visible = True
      Navigator.Buttons.Insert.Visible = False
      Navigator.Buttons.Append.Visible = False
      Navigator.Buttons.Edit.Visible = False
      Navigator.Buttons.Refresh.Visible = False
      Navigator.Buttons.SaveBookmark.Visible = True
      Navigator.Buttons.GotoBookmark.Visible = True
      Navigator.Buttons.Filter.Visible = False
      Navigator.Visible = True
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      DataController.OnBeforePost = TaxaGridTableView1DataControllerBeforePost
      DataController.OnDetailExpanding = TaxaGridTableView1DataControllerDetailExpanding
      NewItemRow.Visible = True
      OptionsBehavior.AlwaysShowEditor = True
      OptionsBehavior.FocusCellOnTab = True
      OptionsBehavior.FocusFirstCellOnNewRecord = True
      OptionsBehavior.GoToNextCellOnEnter = True
      OptionsBehavior.IncSearch = True
      OptionsBehavior.NavigatorHints = True
      OptionsBehavior.FocusCellOnCycle = True
      OptionsCustomize.ColumnFiltering = False
      OptionsCustomize.ColumnGrouping = False
      OptionsCustomize.ColumnMoving = False
      OptionsData.Appending = True
      OptionsData.Inserting = False
      OptionsSelection.HideFocusRectOnExit = False
      OptionsSelection.InvertSelect = False
      OptionsView.CellEndEllipsis = True
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      OptionsView.Indicator = True
      Styles.Background = cxStyle1
      object txID: TcxGridColumn
        Caption = 'ID'
        DataBinding.ValueType = 'Integer'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.ReadOnly = True
        Properties.UseLeftAlignmentOnEditing = False
        HeaderAlignmentHorz = taCenter
        MinWidth = 60
        Options.Filtering = False
        Options.Focusing = False
        Options.Grouping = False
        Options.Moving = False
        SortIndex = 0
        SortOrder = soAscending
      end
      object txCode: TcxGridColumn
        Caption = 'Code'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.ValidateOnEnter = True
        HeaderAlignmentHorz = taCenter
        MinWidth = 60
        Options.Filtering = False
        Options.Grouping = False
        Options.Moving = False
        Width = 84
      end
      object txName: TcxGridColumn
        Caption = 'Name'
        PropertiesClassName = 'TcxTextEditProperties'
        HeaderAlignmentHorz = taCenter
        MinWidth = 60
        Options.Filtering = False
        Options.Grouping = False
        Options.Moving = False
        Width = 256
      end
      object txHigherID: TcxGridColumn
        Caption = 'Higher ID'
        DataBinding.ValueType = 'Integer'
        PropertiesClassName = 'TcxTextEditProperties'
        Properties.UseLeftAlignmentOnEditing = False
        Properties.ValidateOnEnter = True
        HeaderAlignmentHorz = taCenter
        MinWidth = 60
        Options.Filtering = False
        Options.Grouping = False
        Options.Moving = False
      end
      object txEcolGroup: TcxGridColumn
        Caption = 'Ecol Group'
        PropertiesClassName = 'TcxComboBoxProperties'
        Properties.Sorted = True
        Properties.OnNewLookupDisplayText = txEcolGroupPropertiesNewLookupDisplayText
        HeaderAlignmentHorz = taCenter
        MinWidth = 60
        Options.Filtering = False
        Options.Grouping = False
        Options.Moving = False
        Width = 68
      end
    end
    object TaxaGridTableView2: TcxGridTableView
      Navigator.Buttons.CustomButtons = <>
      Navigator.Buttons.First.Visible = True
      Navigator.Buttons.Prior.Visible = True
      Navigator.Buttons.Insert.Visible = False
      Navigator.Buttons.Append.Visible = False
      Navigator.Buttons.Edit.Visible = False
      Navigator.Buttons.Post.Visible = True
      Navigator.Buttons.Refresh.Visible = False
      Navigator.Buttons.SaveBookmark.Visible = False
      Navigator.Buttons.GotoBookmark.Visible = False
      Navigator.Buttons.Filter.Visible = False
      Navigator.Visible = True
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      DataController.OnDetailExpanded = TaxaGridTableView2DataControllerDetailExpanded
      NewItemRow.Visible = True
      OptionsBehavior.AlwaysShowEditor = True
      OptionsBehavior.FocusCellOnTab = True
      OptionsBehavior.FocusFirstCellOnNewRecord = True
      OptionsBehavior.GoToNextCellOnEnter = True
      OptionsBehavior.IncSearch = True
      OptionsBehavior.NavigatorHints = True
      OptionsBehavior.FocusCellOnCycle = True
      OptionsCustomize.ColumnFiltering = False
      OptionsCustomize.ColumnGrouping = False
      OptionsCustomize.ColumnMoving = False
      OptionsData.Appending = True
      OptionsData.Inserting = False
      OptionsSelection.HideFocusRectOnExit = False
      OptionsSelection.InvertSelect = False
      OptionsView.CellEndEllipsis = True
      OptionsView.NoDataToDisplayInfoText = '<No data: default elements will be used>'
      OptionsView.ShowEditButtons = gsebAlways
      OptionsView.GroupByBox = False
      OptionsView.Indicator = True
      Styles.Background = cxStyle4
      Styles.Content = cxStyle2
      object elElement: TcxGridColumn
        Caption = 'Element'
        PropertiesClassName = 'TcxTextEditProperties'
        MinWidth = 200
        SortIndex = 0
        SortOrder = soDescending
        Width = 250
      end
    end
    object TaxaGridTableView3: TcxGridTableView
      Navigator.Buttons.CustomButtons = <>
      Navigator.Buttons.Insert.Visible = False
      Navigator.Buttons.Edit.Visible = False
      Navigator.Buttons.Refresh.Visible = False
      Navigator.Buttons.SaveBookmark.Visible = False
      Navigator.Buttons.GotoBookmark.Visible = False
      Navigator.Buttons.Filter.Visible = False
      Navigator.Visible = True
      DataController.Options = [dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoImmediatePost]
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      NewItemRow.Visible = True
      OptionsBehavior.AlwaysShowEditor = True
      OptionsBehavior.FocusCellOnTab = True
      OptionsBehavior.FocusFirstCellOnNewRecord = True
      OptionsBehavior.GoToNextCellOnEnter = True
      OptionsBehavior.IncSearch = True
      OptionsBehavior.NavigatorHints = True
      OptionsBehavior.FocusCellOnCycle = True
      OptionsCustomize.ColumnFiltering = False
      OptionsCustomize.ColumnGrouping = False
      OptionsCustomize.ColumnMoving = False
      OptionsSelection.HideFocusRectOnExit = False
      OptionsSelection.InvertSelect = False
      OptionsView.CellEndEllipsis = True
      OptionsView.NoDataToDisplayInfoText = '<No data: default units will be used>'
      OptionsView.ShowEditButtons = gsebAlways
      OptionsView.GroupByBox = False
      OptionsView.Indicator = True
      Styles.Background = cxStyle5
      Styles.Content = cxStyle3
      object unUnits: TcxGridColumn
        Caption = 'Units'
        PropertiesClassName = 'TcxTextEditProperties'
        MinWidth = 200
        SortIndex = 0
        SortOrder = soDescending
        Width = 250
      end
    end
    object TaxaGrid1: TcxGridLevel
      GridView = TaxaGridTableView1
      object TaxaGrid2: TcxGridLevel
        GridView = TaxaGridTableView2
        object TaxaGrid3: TcxGridLevel
          GridView = TaxaGridTableView3
        end
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 382
    Width = 577
    Height = 33
    Align = alBottom
    TabOrder = 2
    object FlowPanel1: TFlowPanel
      Left = 176
      Top = 3
      Width = 225
      Height = 25
      AutoSize = True
      AutoWrap = False
      BevelOuter = bvNone
      TabOrder = 0
      object cxButton1: TcxButton
        Left = 0
        Top = 0
        Width = 75
        Height = 25
        Caption = 'Save'
        LookAndFeel.Kind = lfOffice11
        OptionsImage.ImageIndex = 0
        OptionsImage.Images = cxImageList1
        TabOrder = 0
        OnClick = cxButton1Click
      end
      object cxButton2: TcxButton
        Left = 75
        Top = 0
        Width = 75
        Height = 25
        Caption = 'Ok'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 1
        OptionsImage.ImageIndex = 1
        OptionsImage.Images = cxImageList1
        TabOrder = 1
        OnClick = cxButton2Click
      end
      object cxButton3: TcxButton
        Left = 150
        Top = 0
        Width = 75
        Height = 25
        Caption = 'Cancel'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 2
        OptionsImage.ImageIndex = 2
        OptionsImage.Images = cxImageList1
        TabOrder = 2
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 577
    Height = 37
    Align = alTop
    TabOrder = 3
    object LabeledEdit1: TLabeledEdit
      Left = 32
      Top = 8
      Width = 545
      Height = 21
      EditLabel.Width = 24
      EditLabel.Height = 13
      EditLabel.Caption = 'Title:'
      LabelPosition = lpLeft
      TabOrder = 0
    end
  end
  object PopupMenu1: TPopupMenu
    AutoPopup = False
    TrackButton = tbLeftButton
    Left = 512
    Top = 88
    object PartialCompare1: TMenuItem
      Caption = 'Any Part of Field'
      Checked = True
      Hint = 'Any part of field must match'
      OnClick = PartialCompare1Click
    end
    object WholeField1: TMenuItem
      Caption = 'Whole Field'
      Hint = 'Whole field must match'
      OnClick = WholeField1Click
    end
    object StartofField1: TMenuItem
      Caption = 'Start of Field'
      OnClick = StartofField1Click
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object Forward1: TMenuItem
      Caption = 'Forward'
      Checked = True
      Hint = 'Search forward'
      OnClick = Forward1Click
    end
    object Backward1: TMenuItem
      Caption = 'Backward'
      Hint = 'Search backward'
      OnClick = Backward1Click
    end
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'xml'
    Filter = 'XML Lookup File (*.xml)|*.xml'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 448
    Top = 88
  end
  object cxStyleRepository1: TcxStyleRepository
    Left = 416
    Top = 88
    PixelsPerInch = 96
    object cxStyle1: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 10841652
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      TextColor = clWhite
    end
    object cxStyle2: TcxStyle
      AssignedValues = [svColor]
      Color = 16121835
    end
    object cxStyle3: TcxStyle
      AssignedValues = [svColor]
      Color = 16769510
    end
    object cxStyle4: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 16121835
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      TextColor = clNavy
    end
    object cxStyle5: TcxStyle
      AssignedValues = [svColor, svFont, svTextColor]
      Color = 16769510
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      TextColor = clNavy
    end
  end
  object cxImageList1: TcxImageList
    FormatVersion = 1
    DesignInfo = 5767648
    ImageInfo = <
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          00006D422FFF6D422FFF6D422FFF6D422FFF6D422FFF6D422FFF6D422FFF6D42
          2FFF6D422FFF6D422FFF6D422FFF6D422FFF6D422FFF6D422FFF00000000CE72
          6FFFD19792FFCB8E8AFF715A48FFC0B2ABFFC4BCB8FFCAC1BCFFCAC1BCFFCAC1
          BCFFCAC1BCFF8C7667FF944340FF944340FF944340FF6D422FFF00000000CE72
          6FFFD79F9BFFD19792FF715A48FF2E1F18FF5F5046FFFFFFFFFFFFFFFFFFFFFF
          FFFFF0E4DEFF8C7667FF974744FF944340FF944340FF6D422FFF00000000CE72
          6FFFDDA8A3FFD79F9BFF715A48FF0A0A0AFF36241BFFFFFFFFFFF7F1EEFFF0E4
          DEFFE1CABDFF8C7667FF9E504DFF974744FF944340FF6D422FFF00000000CE72
          6FFFE3B0ABFFDDA8A3FF715A48FF715A48FF715A48FF715A48FF715A48FF715A
          48FF715A48FF715A48FFA45956FF9E504DFF974744FF6D422FFF00000000CE72
          6FFFEDBDB8FFE7B5B0FFE0ACA7FFDAA49FFFD49B97FFCB8E8AFFC58682FFBF7E
          79FFB97571FFB26B68FFAB625FFFA45956FF9E504DFF6D422FFF00000000CE72
          6FFFF0C1BCFFEDBDB8FFE7B5B0FFE0ACA7FFDAA49FFFD49B97FFCE938EFFC88A
          86FFC2827EFFBC7975FFB26B68FFAB625FFFA45956FF6D422FFF00000000CE72
          6FFFF0C1BCFFF0C1BCFFC8635CFFC8635CFFC8635CFFC8635CFFC8635CFFC863
          5CFFC8635CFFC8635CFFC8635CFFB5706CFFAE6763FF6D422FFF00000000CE72
          6FFFF0C1BCFFC8635CFFFAF5F3FFF6EEEAFFF2E7E2FFEEE2DAFFEBDCD3FFE7D6
          CBFFE4D0C4FFE1CABDFFE1CABDFFC8635CFFB5706CFF6D422FFF00000000CE72
          6FFFF0C1BCFFC8635CFFFFFFFFFFFCF8F7FFF8F1EEFFF4EAE6FFF0E4DEFFECDF
          D6FFE9D9CFFFE6D3C8FFE2CDC0FFC8635CFFBC7975FF6D422FFF00000000CE72
          6FFFF0C1BCFFC8635CFFFFFFFFFFFFFFFFFFFCF8F7FFF8F1EEFFF4EAE6FFF0E4
          DEFFECDFD6FFE9D9CFFFE6D3C8FFC8635CFFC2827EFF6D422FFF00000000CE72
          6FFFF0C1BCFFC8635CFFFFFFFFFFFFFFFFFFFFFFFFFFFCF8F7FFF8F1EEFFF4EA
          E6FFF0E4DEFFECDFD6FFE9D9CFFFC8635CFFC88A86FF6D422FFF00000000CE72
          6FFFF0C1BCFFC8635CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCF8F7FFF8F1
          EEFFF4EAE6FFF0E4DEFFECDFD6FFC8635CFFD19792FF6D422FFF00000000CE72
          6FFFF0C1BCFFC8635CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCF8
          F7FFF8F1EEFFF4EAE6FFF0E4DEFFC8635CFF0A0A0AFF6D422FFF00000000CE72
          6FFFF0C1BCFFC8635CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFCF8F7FFF8F1EEFFF4EAE6FFC8635CFFC88A86FF6D422FFF00000000CE72
          6FFFCE726FFFCE726FFFCE726FFFCE726FFFCE726FFFCE726FFFCE726FFFCE72
          6FFFCE726FFFCE726FFFCE726FFFCE726FFFCE726FFFCE726FFF}
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
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000AB7E62FFA477
          5AFF955F3FFF8E5739FF7E4020FF7E4020FF000000000000000000000000AB7E
          62FFA4775AFF955F3FFF8E5739FF7E4020FF7E4020FF00000000AB7E62FFFCFA
          FAFFE3C8B8FFCDA38CFFAC7655FF7E4020FF000000000000000000000000AB7E
          62FFFCFAFAFFE3C8B8FFCDA38CFFAC7655FF7E4020FF00000000AB7E62FFFCFA
          FAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF000000000000000000000000AB7E
          62FFFCFAFAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF00000000AB7E62FFFCFA
          FAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF000000000000000000000000AB7E
          62FFFCFAFAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF00000000AB7E62FFFCFA
          FAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF000000000000000000000000AB7E
          62FFFCFAFAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF00000000AB7E62FF9F6B
          4EFF9F6B4EFF915331FF915331FF7E4020FF7E4020FF6F4324FFAB7E62FF9F6B
          4EFF9F6B4EFF915331FF915331FF7E4020FF7E4020FF00000000DDC5A9FFAB7E
          62FFECD8CDFFECD8CDFFCAA089FFAC7655FF7E4020FF9F6B4EFFAB7E62FFECD8
          CDFFECD8CDFFCAA089FFAC7655FF7E4020FF906060FF0000000000000000AB7E
          62FFFFFFFFFFF1E8E5FFEED2C1FFAC7655FF7E4020FFC89890FFAB7E62FFFFFF
          FFFFF1E8E5FFEED2C1FFAC7655FF906060FF0000000000000000000000000000
          0000AB7E62FF9F6B4EFF955F3FFF7E4020FF7E4020FF9F6B4EFFAB7E62FF9F6B
          4EFF955F3FFF7E4020FF7E4020FF000000000000000000000000000000000000
          0000AB7E62FFFCFAFAFFDEC3B1FFAC7655FF7E4020FF00000000AB7E62FFFCFA
          FAFFDEC3B1FFAC7655FF7E4020FF000000000000000000000000000000000000
          0000AB7E62FF9F6B4EFF955F3FFF7E4020FF9F6B4EFF00000000AB7E62FF9F6B
          4EFF955F3FFF7E4020FF9F6B4EFF000000000000000000000000000000000000
          000000000000AB7E62FFFCFAFAFF7E4020FF000000000000000000000000AB7E
          62FFFCFAFAFF7E4020FF00000000000000000000000000000000000000000000
          000000000000AB7E62FFAB7E62FF9F6B4EFF000000000000000000000000AB7E
          62FFAB7E62FF9F6B4EFF00000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000794022FF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000804222FF7D4121FF00000000BD9E8EFF8042
          22FF804222FFBC9D8DFFBC9D8DFF804222FF804222FFBC9D8DFFBB9C8CFF8042
          22FF804222FF9E7058FF804222FF804222FF804222FF7D4222FF000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000804222FF7F4222FF00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000007F4222FF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000AD8267FFB189
          70FFA06E51FF8C5132FF835C47FF0000000000000000A08371FFB48F77FFA270
          54FF905739FF804222FF00000000000000000000000000000000BB9680FFF2E6
          DFFFD5B19DFFB78263FF835C47FF0000000000000000A08371FFF7F0ECFFDAB9
          A6FFBC8A6DFF874A2AFF00000000000000000000000000000000BB9680FFF2E6
          DFFFD5B19DFFBD8768FF835C47FF0000000000000000A08371FFF7F0ECFFDAB9
          A6FFC18E71FF894C2CFF00000000000000000000000000000000B8917AFFE5D2
          C8FFCBA38DFFB67E5FFF825842FFDBDAD9FFDBDADAFF9F806DFFE8DAD2FFCEA9
          93FFB78365FF874A2AFF00000000000000000000000000000000B89175FFAD80
          65FFB78B73FFA97457FF8B5030FF7F4727FF9A6C4FFFB88F78FFB88D75FFA26A
          4AFF894C2BFF834933FF00000000000000000000000000000000B1A9A1FFC9AB
          98FFF2E7E1FFE2C5B4FFA26B4AFF945C42FFAF816AFFE8D9CFFFEBDAD1FFCAA1
          88FF96604CFFA19594FF00000000000000000000000000000000F8F8F8FFADA4
          9EFFB48C75FFAA7B60FF864929FF8C5539FFA67960FFB28972FFA37459FF8D53
          34FFA2948EFFF8F8F8FF0000000000000000000000000000000000000000B4AD
          A9FFC9AD9DFFCCAC98FF98603FFF978276FFA39389FFD4BDB0FFBF967EFF945B
          3AFFAFA5A0FF000000000000000000000000000000000000000000000000D6D4
          D3FF9D7F6EFFC4A594FF815138FFC5C1BFFFC6C2C0FF9F7962FFBC9A88FF8964
          51FFD5D4D3FF0000000000000000000000000000000000000000000000000000
          0000A39389FFB9947DFF93715DFF0000000000000000A08371FFB58E77FF9C89
          7DFF000000000000000000000000000000000000000000000000}
      end>
  end
end
