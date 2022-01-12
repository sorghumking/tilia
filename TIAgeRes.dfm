object AgeModelResultsForm: TAgeModelResultsForm
  Left = 429
  Top = 189
  BorderStyle = bsDialog
  Caption = 'Age Model Results'
  ClientHeight = 384
  ClientWidth = 407
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 89
    Width = 407
    Height = 3
    Cursor = crVSplit
    Align = alTop
    Beveled = True
  end
  object Label1: TLabel
    Left = 312
    Top = 112
    Width = 72
    Height = 13
    Caption = 'Decimal Points:'
  end
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 407
    Height = 89
    Align = alTop
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object ProfGrid1: TProfGrid
    Left = 0
    Top = 92
    Width = 285
    Height = 292
    About = 'v3.4.4.11 for C++Builder XE'
    ColCount = 3
    RowCount = 5
    FixedCols = 1
    FixedRows = 1
    DefaultColWidth = 80
    DefaultRowHeight = 15
    EditControlOptions = [ecoAutoIncreaseRowHeight, ecoAutoIncreaseColumnWidth, ecoUseEditColor, ecoUseEditFontColor, ecoUseCellFont, ecoMakeFlat]
    GridLineWidth = 1
    Options = [pgoFixedVertLine, pgoFixedHorzLine, pgoVertLine, pgoHorzLine, pgoRangeSelect, pgoRowSizing, pgoColSizing, pgoEditing, pgoTabs, pgoAutoIncreaseRowHeights, pgoDrawFocusRectangle, pgoMultiLineCells, pgoMultiSelect, pgoClearCellOnDel, pgoCut, pgoCopy, pgoPaste]
    PrintFooter.Font.Charset = DEFAULT_CHARSET
    PrintFooter.Font.Color = clWindowText
    PrintFooter.Font.Height = -13
    PrintFooter.Font.Name = 'Arial'
    PrintFooter.Font.Style = []
    PrintHeader.Font.Charset = DEFAULT_CHARSET
    PrintHeader.Font.Color = clWindowText
    PrintHeader.Font.Height = -13
    PrintHeader.Font.Name = 'Arial'
    PrintHeader.Font.Style = []
    SortColumn = 1
    SortOnClick = True
    SortOnDblClick = True
    SpreadsheetHeaders = True
    SpreadsheetOptions = [soExcelStyleHeadings, soExcelStyleHeadingHighlight, soExcelStyleSelection, soExcelStyleNavigation, soExcelStyleComments, soColRowHeadingClickSelect, soMouseBuildUpFormula]
    WordWrap = False
    SpreadsheetStyle = ssExcelXP
    SelectionColor = 15387318
    Align = alLeft
    Ctl3D = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentCtl3D = False
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    UsedColumns = <
      item
        AbsoluteNumber = 0
      end
      item
        AbsoluteNumber = 1
      end
      item
        AbsoluteNumber = 2
      end>
    UsedRows = <>
    UsedCells = <
      item
        AbsoluteCol = 1
        AbsoluteRow = 0
        Value = 'Depth'
        HorizontalAlignment = haCenter
        ParentHorizontalAlignment = False
      end
      item
        AbsoluteCol = 2
        AbsoluteRow = 0
        Value = 'Age'
        HorizontalAlignment = haCenter
        ParentHorizontalAlignment = False
      end>
    ColWidths = (
      26
      80
      160)
  end
  object cxSpinEdit1: TcxSpinEdit
    Left = 312
    Top = 128
    Properties.MaxValue = 15.000000000000000000
    Properties.OnChange = cxSpinEdit1PropertiesChange
    Style.BorderStyle = ebs3D
    TabOrder = 2
    Value = 2
    Width = 75
  end
  object cxButton1: TcxButton
    Left = 312
    Top = 351
    Width = 75
    Height = 25
    Caption = 'Close'
    LookAndFeel.Kind = lfOffice11
    ModalResult = 1
    TabOrder = 3
  end
end
