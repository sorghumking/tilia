object OrderForm: TOrderForm
  Left = 432
  Top = 301
  Hint = 'Variables dialog box'
  HelpContext = 67
  BorderIcons = [biSystemMenu, biHelp]
  BorderStyle = bsDialog
  Caption = 'Variables'
  ClientHeight = 416
  ClientWidth = 543
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
  object BitBtn1: TBitBtn
    Left = 496
    Top = 40
    Width = 25
    Height = 25
    Hint = 'Up one row'
    HelpContext = 69
    DoubleBuffered = True
    Glyph.Data = {
      72010000424D7201000000000000760000002800000015000000150000000100
      040000000000FC00000000000000000000001000000000000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
      7777777770007777777777777777777770007777777777777777777770007777
      7777888888877777700077777770000000877777700077777770788880877777
      700077777770F77780877777700077777770F77780877777700077777770F777
      80877777700077777770F77780888887700077700000F7777000007770007777
      0F777777777807777000777770F777777780777770007777770F777778077777
      700077777770F777807777777000777777770F78077777777000777777777070
      7777777770007777777777077777777770007777777777777777777770007777
      77777777777777777000777777777777777777777000}
    ParentDoubleBuffered = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    OnClick = BitBtn1Click
  end
  object BitBtn2: TBitBtn
    Left = 464
    Top = 40
    Width = 25
    Height = 25
    Hint = 'Down one row'
    HelpContext = 68
    DoubleBuffered = True
    Glyph.Data = {
      72010000424D7201000000000000760000002800000015000000150000000100
      040000000000FC00000000000000000000001000000000000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
      7777777770007777777777777777777770007777777777787777777770007777
      7777770887777777700077777777708088777777700077777777077808877777
      7000777777707777808877777000777777077777780887777000777770777777
      77808877700077770FFF777778780887700077700000F7778000007770007777
      7770F77780877777700077777770F77780877777700077777770F77780877777
      700077777770F77780877777700077777770FFFF708777777000777777700000
      0077777770007777777777777777777770007777777777777777777770007777
      77777777777777777000777777777777777777777000}
    ParentDoubleBuffered = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    OnClick = BitBtn2Click
  end
  object BitBtn3: TBitBtn
    Left = 456
    Top = 80
    Width = 75
    Height = 25
    Hint = 'Copy row or block'
    HelpContext = 70
    Caption = 'Mark'
    DoubleBuffered = True
    Glyph.Data = {
      A2040000424DA204000000000000360400002800000009000000090000000100
      0800000000006C00000000000000000000000001000000000000000000000000
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
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
      F9FFFF000000FFFFFFFFFFF9F9FFFF000000FFFFFFFFF9F9F9FFFF000000FFFF
      FFF9F9F9F9FFFF000000FFFFF9F9F9F9F9FFFF000000FFFFFFF9F9F9F9FFFF00
      0000FFFFFFFFF9F9F9FFFF000000FFFFFFFFFFF9F9FFFF000000FFFFFFFFFFFF
      F9FFFF000000}
    ParentDoubleBuffered = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    OnClick = BitBtn3Click
  end
  object BitBtn4: TBitBtn
    Left = 456
    Top = 128
    Width = 75
    Height = 25
    Hint = 'Insert copied row or block above'
    HelpContext = 70
    Caption = 'Above'
    DoubleBuffered = True
    Enabled = False
    Glyph.Data = {
      72010000424D7201000000000000760000002800000015000000150000000100
      040000000000FC00000000000000000000001000000000000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
      7777777770007777777777777777777770007777777777777777777770007777
      7777777777777777700077000000077777777777700077FFFFFF077777777777
      700077FFFFFF077777777777700077FFFFFF0777777777777000770000000777
      77777777700077FFFFFF077777777777700077FFFFFF077777777777700077FF
      FFFF077777777777700077000000077777777777700077777777774770000007
      700077777777744770EFEFE7700077777777444440FEFEF77000777777777447
      70EFEFE770007777777777477000000770007777777777777777777770007777
      77777777777777777000777777777777777777777000}
    ParentDoubleBuffered = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 3
    OnClick = BitBtn4Click
  end
  object BitBtn5: TBitBtn
    Left = 456
    Top = 160
    Width = 75
    Height = 25
    Hint = 'Insert copied row or block below'
    HelpContext = 70
    Caption = 'Below'
    DoubleBuffered = True
    Enabled = False
    Glyph.Data = {
      72010000424D7201000000000000760000002800000015000000150000000100
      040000000000FC00000000000000000000001000000000000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
      7777777770007777777777777777777770007777777777777777777770007777
      7777777777777777700077777777774770000007700077777777744770EFEFE7
      700077777777444440FEFEF7700077777777744770EFEFE77000777777777747
      70000007700077000000077777777777700077FFFFFF077777777777700077FF
      FFFF077777777777700077FFFFFF077777777777700077000000077777777777
      700077FFFFFF077777777777700077FFFFFF077777777777700077FFFFFF0777
      7777777770007700000007777777777770007777777777777777777770007777
      77777777777777777000777777777777777777777000}
    ParentDoubleBuffered = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 4
    OnClick = BitBtn5Click
  end
  object Button1: TButton
    Left = 456
    Top = 200
    Width = 75
    Height = 25
    Hint = 'Overlay graphs'
    HelpContext = 71
    Caption = 'Overlay'
    Enabled = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 456
    Top = 232
    Width = 75
    Height = 25
    Hint = 'Stack graphs'
    HelpContext = 72
    Caption = 'Stack'
    Enabled = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 456
    Top = 264
    Width = 75
    Height = 25
    Hint = 'Skip graph'
    HelpContext = 73
    Caption = 'Skip'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 7
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 456
    Top = 314
    Width = 75
    Height = 25
    Caption = '&Ok'
    ModalResult = 1
    TabOrder = 8
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 456
    Top = 346
    Width = 75
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 9
  end
  object Button6: TButton
    Left = 456
    Top = 378
    Width = 75
    Height = 25
    Caption = '&Help'
    TabOrder = 10
    OnClick = Button6Click
  end
  object BitBtn6: TBitBtn
    Left = 41
    Top = 8
    Width = 25
    Height = 25
    Hint = 'Italic'
    HelpContext = 74
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
    TabOrder = 11
    OnClick = BitBtn6Click
  end
  object BitBtn7: TBitBtn
    Left = 16
    Top = 8
    Width = 25
    Height = 25
    Hint = 'Bold'
    HelpContext = 74
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
    TabOrder = 12
    OnClick = BitBtn7Click
  end
  object BitBtn8: TBitBtn
    Left = 116
    Top = 8
    Width = 25
    Height = 25
    Hint = 'Insert Greek letter'
    HelpContext = 74
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
    TabOrder = 14
    OnClick = BitBtn8Click
  end
  object BitBtn9: TBitBtn
    Left = 66
    Top = 8
    Width = 25
    Height = 25
    Hint = 'Superscript'
    HelpContext = 74
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
    TabOrder = 15
    OnClick = BitBtn9Click
  end
  object BitBtn10: TBitBtn
    Left = 91
    Top = 8
    Width = 25
    Height = 25
    Hint = 'Subscript'
    HelpContext = 74
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
    TabOrder = 13
    OnClick = BitBtn10Click
  end
  object OrderGrid: TcxGrid
    Left = 16
    Top = 40
    Width = 426
    Height = 362
    HelpContext = 67
    TabOrder = 16
    LookAndFeel.NativeStyle = False
    LookAndFeel.SkinName = 'Lilian'
    object OrderGridTableView: TcxGridTableView
      OnMouseUp = OrderGridTableViewMouseUp
      Navigator.Buttons.CustomButtons = <>
      Navigator.Buttons.Insert.Visible = False
      Navigator.Buttons.Delete.Visible = False
      Navigator.Buttons.Edit.Visible = False
      Navigator.Buttons.Post.Visible = False
      Navigator.Buttons.Refresh.Visible = False
      Navigator.Buttons.SaveBookmark.Visible = False
      Navigator.Buttons.GotoBookmark.Visible = False
      Navigator.Buttons.Filter.Visible = False
      Navigator.Visible = True
      OnEditKeyUp = OrderGridTableViewEditKeyUp
      OnFocusedItemChanged = OrderGridTableViewFocusedItemChanged
      OnInitEdit = OrderGridTableViewInitEdit
      DataController.Summary.DefaultGroupSummaryItems = <>
      DataController.Summary.FooterSummaryItems = <>
      DataController.Summary.SummaryGroups = <>
      OptionsBehavior.AlwaysShowEditor = True
      OptionsBehavior.FocusCellOnTab = True
      OptionsBehavior.FocusFirstCellOnNewRecord = True
      OptionsBehavior.GoToNextCellOnEnter = True
      OptionsBehavior.NavigatorHints = True
      OptionsBehavior.FocusCellOnCycle = True
      OptionsCustomize.ColumnFiltering = False
      OptionsCustomize.ColumnGrouping = False
      OptionsCustomize.ColumnMoving = False
      OptionsCustomize.ColumnSorting = False
      OptionsData.CancelOnExit = False
      OptionsData.Deleting = False
      OptionsData.Inserting = False
      OptionsSelection.MultiSelect = True
      OptionsView.CellEndEllipsis = True
      OptionsView.ShowEditButtons = gsebAlways
      OptionsView.ColumnAutoWidth = True
      OptionsView.GroupByBox = False
      OptionsView.HeaderEndEllipsis = True
      OptionsView.Indicator = True
      object orVarName: TcxGridColumn
        Caption = 'VarName'
        PropertiesClassName = 'TcxTextEditProperties'
        OnGetDisplayText = orVarNameGetDisplayText
        FooterAlignmentHorz = taCenter
        HeaderAlignmentHorz = taCenter
        MinWidth = 198
        Options.Filtering = False
        Options.Moving = False
        Options.Sorting = False
        Width = 200
      end
      object orBase: TcxGridColumn
        Caption = 'Base'
        DataBinding.ValueType = 'Boolean'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.Alignment = taCenter
        Properties.FullFocusRect = True
        Properties.ImmediatePost = True
        Properties.OnChange = orBasePropertiesChange
        FooterAlignmentHorz = taCenter
        HeaderAlignmentHorz = taCenter
        Options.Filtering = False
        Options.Moving = False
        Options.Sorting = False
        Width = 40
      end
      object orOverlay: TcxGridColumn
        Caption = 'Overlay'
        DataBinding.ValueType = 'Boolean'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.Alignment = taCenter
        Properties.FullFocusRect = True
        Properties.ImmediatePost = True
        Properties.OnChange = orOverlayPropertiesChange
        FooterAlignmentHorz = taCenter
        HeaderAlignmentHorz = taCenter
        Options.Filtering = False
        Options.Moving = False
        Options.Sorting = False
        Width = 40
      end
      object orStack: TcxGridColumn
        Caption = 'Stack'
        DataBinding.ValueType = 'Boolean'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.Alignment = taCenter
        Properties.FullFocusRect = True
        Properties.ImmediatePost = True
        Properties.OnChange = orStackPropertiesChange
        FooterAlignmentHorz = taCenter
        HeaderAlignmentHorz = taCenter
        Options.Filtering = False
        Options.Moving = False
        Options.Sorting = False
        Width = 40
      end
      object orSkip: TcxGridColumn
        Caption = 'Skip'
        DataBinding.ValueType = 'Boolean'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.Alignment = taCenter
        Properties.FullFocusRect = True
        Properties.ImmediatePost = True
        Properties.OnChange = orSkipPropertiesChange
        FooterAlignmentHorz = taCenter
        HeaderAlignmentHorz = taCenter
        Options.Filtering = False
        Options.Moving = False
        Options.Sorting = False
        Width = 40
      end
      object orMark: TcxGridColumn
        DataBinding.ValueType = 'Boolean'
        PropertiesClassName = 'TcxCheckBoxProperties'
        Properties.Alignment = taCenter
        Properties.Glyph.Data = {
          EA040000424DEA04000000000000360400002800000012000000090000000100
          080000000000B400000000000000000000000001000000000000000000000000
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
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFF9FFFF0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFF9F9FFFF
          0000FFFFFFFFFFFFFFFFFFFFFFFFFFF9F9F9FFFF0000FFFFFFFFFFFFFFFFFFFF
          FFFFF9F9F9F9FFFF0000FFFFFFFFFFFFFFFFFFFFFFF9F9F9F9F9FFFF0000FFFF
          FFFFFFFFFFFFFFFFFFFFF9F9F9F9FFFF0000FFFFFFFFFFFFFFFFFFFFFFFFFFF9
          F9F9FFFF0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFF9F9FFFF0000FFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFF9FFFF0000}
        Properties.GlyphCount = 2
        Properties.ImmediatePost = True
        Properties.OnEditValueChanged = orMarkPropertiesEditValueChanged
        MinWidth = 10
        Width = 11
      end
    end
    object OrderGridLevel1: TcxGridLevel
      GridView = OrderGridTableView
    end
  end
end
