﻿/////////////////////////////////////////////////////////////////
//
// Filename          :  MILCODE.H
// Content           :  function capi of McodeAlloc
// Revision          :  10.10.0614
//
// Copyright ?Matrox Electronic Systems Ltd., 1992-2015.
// All Rights Reserved
//
/////////////////////////////////////////////////////////////////

#ifndef __MILCODE_H__
#define __MILCODE_H__

#if (!M_MIL_LITE) // MIL FULL ONLY

#if M_MIL_USE_RT
#ifdef M_CODE_EXPORTS
#define MIL_CODE_DLLFUNC __declspec(dllexport)
#else
#define MIL_CODE_DLLFUNC __declspec(dllimport)
#endif
#else
#define MIL_CODE_DLLFUNC
#endif

/* C++ directive if needed */
#ifdef __cplusplus
extern "C"
{
#endif


/**************************************************************************/
/* CAPI defines                                                           */
/**************************************************************************/

/**************************************************************************/
/* Index values                                                           */
/**************************************************************************/
#define M_GRADE_RESULT_OFFSET   10L                                        // =utilities= 
#define M_GRADE_RESULT_INDEX(i) ((i == M_ALL || i == M_DEFAULT) ? 0 : (i+1) << M_GRADE_RESULT_OFFSET)


#if OldDefinesSupport
   #define M_VERIFY_RESULT_OFFSET         M_GRADE_RESULT_OFFSET
   #define M_VERIFY_RESULT_INDEX(i)       M_GRADE_RESULT_INDEX(i)
   MIL_DEPRECATED(M_VERIFY_RESULT_OFFSET, 1010)
   MIL_DEPRECATED(M_VERIFY_RESULT_INDEX , 1010)
#endif

/**************************************************************************/
/* McodeAlloc()  Code types                                               */
/**************************************************************************/

#define M_CODE39                          0x00000001
#define M_DATAMATRIX                      0x00000002
#define M_EAN13                           0x00000004
#define M_MAXICODE                        0x00000008
#define M_INTERLEAVED25                   0x00000010
#define M_CODE128                         0x00000020
#define M_BC412                           0x00000040
#define M_CODABAR                         0x00000080
#define M_PDF417                          0x00000100
#define M_POSTNET                         0x00000200
#define M_PLANET                          0x00000400
#define M_UPC_A                           0x00000800
#define M_UPC_E                           0x00001000
#define M_PHARMACODE                      0x00002000
#if OldDefinesSupport
   #define M_RSSCODE                      0x00004000
   #define M_RSS14                        0x00008000
   #define M_RSS14_TRUNCATED              0x00010000
   #define M_RSS_LIMITED                  0x00020000
   #define M_RSS_EXPANDED                 0x00040000
   #define M_RSS14_STACKED                0x00080000
   #define M_RSS14_STACKED_OMNI           0x00100000
   #define M_RSS_EXPANDED_STACKED         0x00200000
   MIL_DEPRECATED(M_RSSCODE             , 1010)
   MIL_DEPRECATED(M_RSS14               , 1010)
   MIL_DEPRECATED(M_RSS14_TRUNCATED     , 1010)
   MIL_DEPRECATED(M_RSS_LIMITED         , 1010)
   MIL_DEPRECATED(M_RSS_EXPANDED        , 1010)
   MIL_DEPRECATED(M_RSS14_STACKED       , 1010)
   MIL_DEPRECATED(M_RSS14_STACKED_OMNI  , 1010)
   MIL_DEPRECATED(M_RSS_EXPANDED_STACKED, 1010)
#endif
#define M_GS1_DATABAR                     0x00004000
// RSS Sub type section...
#define M_GS1_DATABAR_OMNI                0x00008000
#define M_GS1_DATABAR_TRUNCATED           0x00010000
#define M_GS1_DATABAR_LIMITED             0x00020000
#define M_GS1_DATABAR_EXPANDED            0x00040000
#define M_GS1_DATABAR_STACKED             0x00080000
#define M_GS1_DATABAR_STACKED_OMNI        0x00100000
#define M_GS1_DATABAR_EXPANDED_STACKED    0x00200000
// ...End of RSS Sub type section.
#define M_EAN8                   0x00400000
#define M_MICROPDF417            0x00800000
#define M_COMPOSITECODE          0x01000000
#if OldDefinesSupport
   #define M_UCCEAN128           0x02000000
   MIL_DEPRECATED(M_UCCEAN128, 1010)
#endif
#define M_GS1_128                0x02000000
#define M_QRCODE                 0x04000000
#define M_MICROQRCODE            0x04000002
#define M_CODE93                 0x08000000
#define M_TRUNCATED_PDF417       0x08000005
#define M_4_STATE                0x08000007
#define M_EAN14                  0x08000009
#define M_INDUSTRIAL25           0x00000011
#define M_AZTEC                  0x0800000A

// Allocation control flags
#if OldDefinesSupport
   #define M_CONTROL_FLAG        0x00019400L
   MIL_DEPRECATED(M_CONTROL_FLAG, 1010)
#endif

/**************************************************************************/
/* McodeModel()  operations                                               */
/**************************************************************************/
#define M_ADD                        0x0000L // Already defined in mil.h, milim.h and milocr.h as 0x0000L
#define M_FIND                            2L
#define M_DELETE                          3L // Already defined in milblob.h, miledge.h, milmetrol.h and milmod.h as 3L


/**************************************************************************/
/* McodeInquire(), McodeGetResult(), McodeControl() parameters            */
/**************************************************************************/

#define M_OWNER_SYSTEM                  1101L     // already define in mil.h
#define M_CODE_TYPE               0x00000001L
#define M_WRITE_SIZE_X            0x00000002L
#if (M_MIL_USE_UNICODE && !M_MIL_UNICODE_API && !M_COMPILING_MILDLL)
#define M_STRING                           (3L | M_CLIENT_ASCII_MODE)   // Already define as 3L
#else
#define M_STRING                           3L     // Already define as 3L
#endif
#define M_FOREGROUND_VALUE                 4L     // Already define as 4L
#define M_WRITE_SIZE_Y            0x00000005L
#define M_THRESHOLD                        82      // Deprecated; Already define as 82
#define M_THRESHOLD_MODE                  33L      // Replaces M_THRESHOLD; Already defined in miledge.h
#define M_MINIMUM_CONTRAST               600L      // Deprecated; Already defined in milstr.h
#define M_THRESHOLD_VALUE                953L      // Supersedes the M_MINIMUM_CONTRAST control
#define M_STOP_READ                      610L      // Already defined in milstr.h
#define M_STATUS                  0x00008002L
#define M_FOREGROUND_WHITE              0x80L      // Already define as 0x80L
#define M_FOREGROUND_BLACK             0x100L      // Already define as 0x100L
#define M_FOREGROUND_ANY          M_FOREGROUND_WHITE+M_FOREGROUND_BLACK // Alread defined in milmod.h
#define M_SEARCH_ANGLE            0x00000100L      // Already define as 0x00000100L
#define M_SEARCH_ANGLE_DELTA_NEG  0x00000200L      // Already define as 0x00000200L
#define M_SEARCH_ANGLE_DELTA_POS  0x00000400L      // Already define as 0x00000400L
#define M_SEARCH_ANGLE_STEP       0x00000600L      // Already define as 0x00000400L
#define M_ANGLE                   0x00000800L      // Already define as 0x00000800L
#define M_CELL_SIZE               0x00001000L
#define M_SCORE                   0x00001400L      // Already defined in milpat.h
#define M_CELL_SIZE_MIN           0x00002000L
#define M_CELL_SIZE_MAX           0x00004000L
#define M_ASPECT_RATIO                  6001L      // Already define as 6001L
#define M_CELL_NUMBER_X           0x00008000L
#define M_CELL_NUMBER_Y           0x00008001L
#define M_CELL_NUMBER_X_MIN       0x00008010L
#define M_CELL_NUMBER_Y_MIN       0x00008011L
#define M_CELL_NUMBER_X_MAX       0x00008012L
#define M_CELL_NUMBER_Y_MAX       0x00008013L
#define M_DATAMATRIX_SHAPE        0x00008014L
#define M_WRITE_CELL_NUMBER_X     0x00008015L
#define M_WRITE_CELL_NUMBER_Y     0x00008016L
#define M_SPEED                            8L      // Already define in milpat.h
#define M_STRING_SIZE             MAKE_INT64(0x0000050000000000) //Same as in Milocr and Milstr
#define M_STRING_SIZE_MIN                500L      // Already defined in milstr.h
#define M_STRING_SIZE_MAX                 62L      // Already defined in milocr.h
#define M_STRING_FORMAT           0x00000048L                 
#define M_ERROR_CORRECTION        0x00008004L
#define M_ENCODING                0x00008005L
#define M_DOT_SPACING             0x00008007L
#define M_CHECK_FINDER_PATTERN    0x0000800CL
#define M_TOTAL_STRING_SIZE       0x0000800FL
#define M_DISTORTION              0x0000801BL
#define M_CHECK_QUIET_ZONE        0x0000801CL
#define M_ECC_CORRECTED_NUMBER    0x00008020L
#define M_POSITION_ACCURACY               13L      // Already defined in milpat.h
#define M_RECOMMENDED_APERTURE_SIZE 0x00008023L

#define M_UNEVEN_GRID_STEP                5L
#define M_PERSPECTIVE_UNEVEN_GRID_STEP    7L


#define M_POSITION_X              0x00003400L      // Already define as 0x00003400L
#define M_POSITION_Y              0x00004400L      // Already define as 0x00004400L

#define M_DISTANCE_MAX            0x00004900L
#if OldDefinesSupport
   #define M_SCAN_REVERSE         0x00004B00L
   MIL_DEPRECATED(M_SCAN_REVERSE, 1010)
#endif
#define M_USE_PRESEARCH           0x00004D00L
#define M_BEARER_BAR              0x00005200L

#if OldDefinesSupport
   #define M_DATAMATRIX_TYPE      0x00004E00L
   MIL_DEPRECATED(M_DATAMATRIX_TYPE, 1010)
#endif
                                              //Undocumented flag usefull to increase
                                              //speed if the user know his Datamatrix
                                              //are always obsolete or never obsolete...
                                              //Possible values are : M_OBSOLETE, M_REGULAR or
                                              //M_ANY. M_ANY is the default value since it allow
                                              //to read both type of Datamatrix.
#define M_SCANLINE_HEIGHT         0x00004F00L //Usefull to control the height of the scanline (in pixel).
#if OldDefinesSupport
   #define M_SCANLINE_FREQUENCE   0x00005000L 
   MIL_DEPRECATED(M_SCANLINE_FREQUENCE, 1010)
#endif
                                                       //Obsolete : replaced by M_SCANLINE_STEP
                                                       //keep here for backward compatibility
#define M_SCANLINE_STEP           0x00005000L //Usefull to control the distance between scanline.
#define M_SUB_TYPE                0x00005100L //To enable code sub type for a read operation.
                                              //Example : M_RSS14, M_RSS_LIMITED,...



#define M_GRADING_STANDARD               0x00008040L
#if OldDefinesSupport
   #define M_VERIFICATION_STANDARD       M_GRADING_STANDARD 
    MIL_DEPRECATED(M_VERIFICATION_STANDARD, 1010)
#endif 
#define M_MAXIMUM_CALIBRATED_REFLECTANCE 0x00008041L
#define M_MINIMUM_CALIBRATED_REFLECTANCE 0x00008042L
#define M_APERTURE_MODE                  0x00008043L
#define M_RELATIVE_APERTURE_FACTOR       0x00008044L
#define M_ABSOLUTE_APERTURE_SIZE         0x00008045L
#define M_PIXEL_SIZE_IN_MM               0x00008046L
#define M_SCANLINE_INPUT_UNITS                  0x00008047L
#define M_ABSOLUTE_APERTURE_SIZE_INPUT_UNITS    0x00008048L
#define M_SEARCH_ANGLE_INPUT_UNITS              0x00008049L
#define M_CELL_SIZE_INPUT_UNITS                 0x0000804AL
#define M_DOT_SPACING_INPUT_UNITS               0x0000804BL
#define M_CODE_FLIP                             1413L
#define M_IS_GS1                                1499L

#define M_REFLECTANCE_CALIBRATION               1634L
#define M_SYSTEM_RESPONSE_CALIBRATION           1635L
#define M_MEAN_LIGHT_CALIBRATION                1636L
#define M_MEAN_LIGHT_TARGET                     1637L
#define M_SYSTEM_RESPONSE_TARGET                1638L
#define M_INSPECTION_BAND_RATIO                 1649L
#define M_NUMBER_OF_SCANLINES                   1653L

#define M_AIMDPM_CALIBRATION_RESULTS            1654L
#define M_APERTURE_SIZE_USED                    1655L
#define M_DOT_SPACING_USED                      1656L

#define M_EXTENDED_AREA_REFLECTANCE_CHECK       1657L

#define M_FINDER_PATTERN_INPUT_UNITS            1679L
#define M_FINDER_PATTERN_MAX_GAP                1683L
#define M_FINDER_PATTERN_MINIMUM_LENGTH         1684L
#define M_FINDER_PATTERN_EXHAUSTIVE_SEARCH      1685L

#if OldDefinesSupport
   #define M_MAX_GAP                            M_FINDER_PATTERN_MAX_GAP
   #define M_MINIMUM_LSIDE_LENGTH               M_FINDER_PATTERN_MINIMUM_LENGTH
   #define M_EXHAUSTIVE_LSIDE_SEARCH            M_FINDER_PATTERN_EXHAUSTIVE_SEARCH
   MIL_DEPRECATED(M_MAX_GAP                , 1010)
   MIL_DEPRECATED(M_MINIMUM_LSIDE_LENGTH   , 1010)
   MIL_DEPRECATED(M_EXHAUSTIVE_LSIDE_SEARCH, 1010)
#endif


#define M_RESULT_OUTPUT_UNITS          1300L // Also in milim.h

// Aperture related control values
#define M_ABSOLUTE                       1L          // also defined in milpat.h, milcolor.h
#define M_RELATIVE                       21L         // also defined in milcolor.h
#define M_AUTO                           444L        // also defined in miledge.h, milmetrol.h, milmod.h, milocr.h, milcolor.h

// M_USE_PRESEARCH related control values
#define M_STAT_BASE                      M_ENABLE
#define M_FINDER_PATTERN_BASE            2L


// input units control values
#define M_PIXEL                          0x1000L
#define M_WORLD                          0x2000L

// Parameters for output units
#define M_PIXEL                              0x1000L
#define M_WORLD                              0x2000L
#define M_ACCORDING_TO_CALIBRATION             1301L

// M_SEARCH_ANGLE control value
#define M_ACCORDING_TO_REGION            0x40000000L 

#define M_SIZE_X                        1536L // 0x600
#define M_SIZE_Y                        1537L // 0x601
#define M_TOP_LEFT_X                    1004L
#define M_TOP_LEFT_Y                    1005L
#define M_TOP_RIGHT_X                   1014L
#define M_TOP_RIGHT_Y                   1015L
#define M_BOTTOM_LEFT_X                 1016L
#define M_BOTTOM_LEFT_Y                 1017L
#define M_BOTTOM_RIGHT_X                1018L
#define M_BOTTOM_RIGHT_Y                1019L
#if OldDefinesSupport
   #define M_FULL_EXTENT_TOP_LEFT_X     1020L
   #define M_FULL_EXTENT_TOP_LEFT_Y     1021L
   #define M_FULL_EXTENT_TOP_RIGHT_X    1022L
   #define M_FULL_EXTENT_TOP_RIGHT_Y    1023L
   #define M_FULL_EXTENT_BOTTOM_LEFT_X  1024L
   #define M_FULL_EXTENT_BOTTOM_LEFT_Y  1025L
   #define M_FULL_EXTENT_BOTTOM_RIGHT_X 1026L
   #define M_FULL_EXTENT_BOTTOM_RIGHT_Y 1027L
   MIL_DEPRECATED(M_FULL_EXTENT_TOP_LEFT_X    , 1010)
   MIL_DEPRECATED(M_FULL_EXTENT_TOP_LEFT_Y    , 1010)
   MIL_DEPRECATED(M_FULL_EXTENT_TOP_RIGHT_X   , 1010)
   MIL_DEPRECATED(M_FULL_EXTENT_TOP_RIGHT_Y   , 1010)
   MIL_DEPRECATED(M_FULL_EXTENT_BOTTOM_LEFT_X , 1010)
   MIL_DEPRECATED(M_FULL_EXTENT_BOTTOM_LEFT_Y , 1010)
   MIL_DEPRECATED(M_FULL_EXTENT_BOTTOM_RIGHT_X, 1010)
   MIL_DEPRECATED(M_FULL_EXTENT_BOTTOM_RIGHT_Y, 1010)
#endif

#define M_QUIET_ZONE_TOP_LEFT_X         1020L    
#define M_QUIET_ZONE_TOP_LEFT_Y         1021L    
#define M_QUIET_ZONE_TOP_RIGHT_X        1022L    
#define M_QUIET_ZONE_TOP_RIGHT_Y        1023L    
#define M_QUIET_ZONE_BOTTOM_LEFT_X      1024L    
#define M_QUIET_ZONE_BOTTOM_LEFT_Y      1025L    
#define M_QUIET_ZONE_BOTTOM_RIGHT_X     1026L    
#define M_QUIET_ZONE_BOTTOM_RIGHT_Y     1027L    

#define M_EXTENDED_AREA_TOP_LEFT_X      1028L        
#define M_EXTENDED_AREA_TOP_LEFT_Y      1029L       
#define M_EXTENDED_AREA_TOP_RIGHT_X     1030L     
#define M_EXTENDED_AREA_TOP_RIGHT_Y     1031L       
#define M_EXTENDED_AREA_BOTTOM_LEFT_X   1032L    
#define M_EXTENDED_AREA_BOTTOM_LEFT_Y   1033L     
#define M_EXTENDED_AREA_BOTTOM_RIGHT_X  1034L   
#define M_EXTENDED_AREA_BOTTOM_RIGHT_Y  1035L    

#define M_USER_LABEL                    228L   // also defined in milreg.h


// Verification results
// Modifiers
#define M_LINEAR_COMPONENT                      0x00004D00L
#define M_2D_COMPONENT                          0x00004E00L
// Grades
// Available value range for flags: 0x9000 - 0x90FF
#define M_OVERALL_SYMBOL_GRADE                  0x00009000L
#define M_SYMBOL_CONTRAST_GRADE                 0x00009001L
#define M_PRINT_GROWTH_GRADE                    0x00009002L
#define M_AXIAL_NONUNIFORMITY_GRADE             0x00009003L
#define M_UNUSED_ERROR_CORRECTION_GRADE         0x00009004L
#define M_DECODE_GRADE                          0x00009005L
#define M_EDGE_DETERMINATION_GRADE              0x00009006L // Deprecated flag
#define M_MINIMUM_REFLECTANCE_GRADE             0x00009007L
#define M_MINIMUM_EDGE_CONTRAST_GRADE           0x00009008L // Deprecated flag
#define M_MODULATION_GRADE                      0x00009009L
#define M_DEFECTS_GRADE                         0x0000900AL
#define M_DECODABILITY_GRADE                    0x0000900BL
#define M_RAP_GRADE                             0x0000900CL // Deprecated flag
#define M_SYMBOL_BASED_GRADE                    0x0000900DL // Deprecated flag
#define M_START_STOP_PATTERN_GRADE              0x0000900EL
#define M_SCAN_DECODE_GRADE                     0x0000900FL
#define M_SCAN_SYMBOL_CONTRAST_GRADE            0x00009010L
#define M_SCAN_EDGE_CONTRAST_MINIMUM_GRADE      0x00009011L
#define M_SCAN_REFLECTANCE_MINIMUM_GRADE        0x00009012L
#define M_SCAN_MODULATION_GRADE                 0x00009013L
#define M_SCAN_DEFECTS_GRADE                    0x00009014L
#define M_SCAN_DECODABILITY_GRADE               0x00009015L
#define M_SCAN_REFLECTANCE_PROFILE_GRADE        0x00009016L
#define M_SCAN_EDGE_DETERMINATION_GRADE         0x00009017L
#define M_SCAN_GUARD_PATTERN_GRADE              0x00009018L
#define M_SCAN_QUIET_ZONE_GRADE                 0x00009019L
#define M_SCAN_WIDE_TO_NARROW_RATIO_GRADE       0x0000901AL
#define M_SCAN_INTERCHARACTER_GAP_GRADE         0x0000901BL

#define M_ROW_OVERALL_GRADE                     0x00009030L

#define M_CODEWORD_YIELD_GRADE                  0x00009040L
#define M_CODEWORD_DECODABILITY_GRADE           0x00009041L
#define M_CODEWORD_DEFECTS_GRADE                0x00009042L
#define M_CODEWORD_MODULATION_GRADE             0x00009043L

#define M_GRID_NONUNIFORMITY_GRADE              0x00009044L
#define M_FIXED_PATTERN_DAMAGE_GRADE            0x00009045L
#define M_CELL_CONTRAST_GRADE                   0x00009046L
#define M_CELL_MODULATION_GRADE                 0x00009047L
#define M_FORMAT_INFORMATION_GRADE              0x00009048L
#define M_VERSION_INFORMATION_GRADE             0x00009049L
#define M_CONTRAST_UNIFORMITY_GRADE             0x0000904AL
#define M_CODEWORD_REFLECTANCE_MARGIN_GRADE     0x0000904BL
#define M_REFLECTANCE_MARGIN_GRADE              0x0000904CL

#define M_FIXED_PATTERN_DAMAGE_L1_GRADE         0x0000904DL
#define M_FIXED_PATTERN_DAMAGE_L2_GRADE         0x0000904EL
#define M_FIXED_PATTERN_DAMAGE_QZL1_GRADE       0x0000904FL
#define M_FIXED_PATTERN_DAMAGE_QZL2_GRADE       0x00009050L
#define M_FIXED_PATTERN_DAMAGE_CLOCKTRACK_SOLID_GRADE 0x00009051L
#define M_FIXED_PATTERN_DAMAGE_AVERAGE_GRADE    0x00009052L
#define M_FIXED_PATTERN_DAMAGE_A1_GRADE         0x00009053L
#define M_FIXED_PATTERN_DAMAGE_A2_GRADE         0x00009054L
#define M_FIXED_PATTERN_DAMAGE_A3_GRADE         0x00009055L
#define M_FIXED_PATTERN_DAMAGE_B1_GRADE         0x00009056L
#define M_FIXED_PATTERN_DAMAGE_B2_GRADE         0x00009057L
#define M_FIXED_PATTERN_DAMAGE_C_GRADE          0x00009058L
#define M_FORMAT_INFORMATION_1_GRADE            0x00009059L
#define M_FORMAT_INFORMATION_2_GRADE            0x0000905AL
#define M_VERSION_INFORMATION_1_GRADE           0x0000905BL
#define M_VERSION_INFORMATION_2_GRADE           0x0000905CL

#define M_EXTENDED_AREA_CODEWORD_MODULATION_GRADE             0x0000905DL
#define M_EXTENDED_AREA_MODULATION_GRADE                      0x0000905EL
#define M_EXTENDED_AREA_SYMBOL_CONTRAST_GRADE                 0x0000905FL
#define M_EXTENDED_AREA_FIXED_PATTERN_DAMAGE_GRADE            0x00009060L
#define M_EXTENDED_AREA_FIXED_PATTERN_DAMAGE_L1_GRADE         0x00009061L
#define M_EXTENDED_AREA_FIXED_PATTERN_DAMAGE_L2_GRADE         0x00009062L
#define M_EXTENDED_AREA_FIXED_PATTERN_DAMAGE_QZL1_GRADE       0x00009063L
#define M_EXTENDED_AREA_FIXED_PATTERN_DAMAGE_QZL2_GRADE       0x00009064L
#define M_EXTENDED_AREA_FIXED_PATTERN_DAMAGE_CLOCKTRACK_SOLID_GRADE 0x00009065L
#define M_EXTENDED_AREA_FIXED_PATTERN_DAMAGE_AVERAGE_GRADE    0x00009066L
#define M_EXTENDED_AREA_FIXED_PATTERN_DAMAGE_A1_GRADE         0x00009067L
#define M_EXTENDED_AREA_FIXED_PATTERN_DAMAGE_A2_GRADE         0x00009068L
#define M_EXTENDED_AREA_FIXED_PATTERN_DAMAGE_A3_GRADE         0x00009069L
#define M_EXTENDED_AREA_FIXED_PATTERN_DAMAGE_B1_GRADE         0x0000906AL
#define M_EXTENDED_AREA_FIXED_PATTERN_DAMAGE_B2_GRADE         0x0000906BL
#define M_EXTENDED_AREA_FIXED_PATTERN_DAMAGE_C_GRADE          0x0000906CL

// Measured paramaeters results flags
// Available value range for flags : 0xA000 - 0xA0FF
#define M_SYMBOL_CONTRAST                       0x0000A000L
#define M_MINIMUM_EDGE_CONTRAST                 0x0000A001L // Deprecated flag
#define M_MINIMUM_REFLECTANCE                   0x0000A002L
#define M_MAXIMUM_REFLECTANCE                   0x0000A003L // Deprecated flag
#define M_MODULATION                            0x0000A004L // Deprecated flag
#define M_DEFECTS                               0x0000A005L // Deprecated flag
#define M_DECODABILITY                          0x0000A006L // Deprecated flag
#define M_MAXIMUM_ERN                           0x0000A007L // Deprecated flag
#define M_AXIAL_NONUNIFORMITY                   0x0000A008L
#define M_PRINT_GROWTH                          0x0000A009L
#define M_UNUSED_ERROR_CORRECTION               0x0000A00AL
#define M_SCAN_SYMBOL_CONTRAST                  0x0000A00BL
#define M_SCAN_REFLECTANCE_MINIMUM              0x0000A00CL
#define M_SCAN_REFLECTANCE_MAXIMUM              0x0000A00DL
#define M_SCAN_MODULATION                       0x0000A00EL
#define M_SCAN_ERN_MAXIMUM                      0x0000A00FL
#define M_SCAN_DEFECTS                          0x0000A010L
#define M_SCAN_DECODABILITY                     0x0000A011L
#define M_SCAN_EDGE_CONTRAST_MINIMUM            0x0000A012L
#define M_SCAN_GUARD_PATTERN                    0x0000A013L
#define M_SCAN_QUIET_ZONE                       0x0000A014L
#define M_SCAN_WIDE_TO_NARROW_RATIO             0x0000A015L
#define M_SCAN_INTERCHARACTER_GAP               0x0000A016L
#define M_SCAN_PRINT_CONTRAST_SIGNAL            0x0000A017L

#define M_SCAN_PROFILE_START_X                  0x0000A030L
#define M_SCAN_PROFILE_START_Y                  0x0000A031L
#define M_SCAN_PROFILE_END_X                    0x0000A032L
#define M_SCAN_PROFILE_END_Y                    0x0000A033L
#define M_SCAN_REFLECTANCE_PROFILE_VALUES       0x0000A034L
#define M_SCAN_REFLECTANCE_PROFILE_LENGTH       0x0000A035L

#define M_CODEWORD_YIELD                        0x0000A040L
#define M_CODEWORD_DECODABILITY                 0x0000A041L
#define M_CODEWORD_DEFECTS                      0x0000A042L
#define M_CODEWORD_MODULATION                   0x0000A043L

#define M_GRID_NONUNIFORMITY                    0x0000A044L
#define M_CELL_CONTRAST                         0x0000A045L
#define M_CONTRAST_UNIFORMITY                   0x0000A046L
#define M_CODEWORD_REFLECTANCE_MARGIN           0x0000A047L

#define M_R_MIN                   0x0000A048L
#define M_R_MAX                   0x0000A049L

#define M_EXTENDED_AREA_CODEWORD_MODULATION     0x0000A04AL
#define M_EXTENDED_AREA_REFLECTANCE_MINIMUM     0x0000A04BL
#define M_EXTENDED_AREA_REFLECTANCE_MAXIMUM     0x0000A04CL
#define M_EXTENDED_AREA_SYMBOL_CONTRAST         0x0000A04DL
#define M_ASTERISK                              0x0000A04EL

// General
// Available value range for flags: 0xB000 - 0xB0FF
#define M_NUMBER_OF_ROWS                        0x0000B000L
#define M_NUMBER_OF_SCANS_PER_ROW               0x0000B001L
#define M_NUMBER_OF_SCANS                       0x0000B002L
#define M_NUMBER_OF_CODEWORDS                   0x0000B003L
#define M_NUMBER_OF_ERROR_CORRECTION_CODEWORDS  0x0000B004L
#define M_NUMBER_OF_ERRORS                      0x0000B005L
#define M_NUMBER_OF_ERASURES                    0x0000B006L
#define M_NUMBER_OF_DATA_CODEWORDS              0x0000B007L
#define M_DATA_CODEWORDS                        0x0000B009L
#define M_QUIET_ZONE_INCLUDED                   0x0000B00AL
#define M_EXTENDED_AREA_QUIET_ZONE_INCLUDED     0x0000B00BL


#define M_ESCAPE_SEQUENCE         0x00000010L
#define M_GS1_FORMAT              0x00000040L

#define M_SIZE_BYTE                     5061L        // already defined as 5061L
#define M_CODE_MODEL_ID                 5064L
#define M_NUMBER_OF_CODE_MODELS         5065L
#define M_CODE_MODEL_INDEX              5066L
#define M_SEARCH_ANGLE_MODE             0x00000080L // Already define as 0x00000080L
#define M_NUMBER                        1009L       // Already defined in mil.h
#define M_TOTAL_NUMBER                  1010L
#define M_PREPROCESSED                  14L         // Already define in MilPat.h

/**************************************************************************/
/* McodeSave(), McodeRestore()                                            */
/**************************************************************************/
#define M_MEMORY                         (M_APP_INQUIRE_SYS_START+120L) /*5120*/  // Already defined in Mil.h
#define M_INTERACTIVE                    M_NULL // Already defined in mil.h, milcal.h, miledge.h, milmeas.h, milocr.h, milpat.h, milmod.h

#define M_SAVE                             0x100L        // Already defines in    milmod.h, milocr.h
#define M_RESTORE                           0x10L
#define M_LOAD                                 1L        // Already defines in    milmod.h, milmeas.h, mil.h
#define M_INQUIRE_SIZE_BYTE                    2L        // Already defines in    milmod.h
#define M_SAVE_REPORT                      0x200L

/**************************************************************************/
/* McodeInquire(), McodeGetResult(), McodeControl() parameter values      */
/**************************************************************************/

#define M_TIMEOUT                 2077L         // already defined in mil.h    
#define M_TIMEOUT_END             10L           // Also defined in milmod.h
#define M_ECC_050                 0             // These numbers are importants!!
#define M_ECC_080                 1
#define M_ECC_100                 2
#define M_ECC_140                 3
#define M_ECC_NONE                4
#define M_ECC_CHECK_DIGIT         5
#define M_ECC_UNKNOWN             6
#define M_ECC_200                 7
#define M_ECC_REED_SOLOMON_0      10
#define M_ECC_REED_SOLOMON_1      (M_ECC_REED_SOLOMON_0 + 1)
#define M_ECC_REED_SOLOMON_2      (M_ECC_REED_SOLOMON_0 + 2)
#define M_ECC_REED_SOLOMON_3      (M_ECC_REED_SOLOMON_0 + 3)
#define M_ECC_REED_SOLOMON_4      (M_ECC_REED_SOLOMON_0 + 4)
#define M_ECC_REED_SOLOMON_5      (M_ECC_REED_SOLOMON_0 + 5)
#define M_ECC_REED_SOLOMON_6      (M_ECC_REED_SOLOMON_0 + 6)
#define M_ECC_REED_SOLOMON_7      (M_ECC_REED_SOLOMON_0 + 7)
#define M_ECC_REED_SOLOMON_8      (M_ECC_REED_SOLOMON_0 + 8)
#define M_ECC_REED_SOLOMON        19
#define M_ECC_010                 20
#define M_ECC_040                 21
#define M_ECC_060                 22
#define M_ECC_070                 23
#define M_ECC_090                 24
#define M_ECC_110                 25
#define M_ECC_120                 26
#define M_ECC_130                 27
#define M_ECC_COMPOSITE           28
#define M_ECC_L                   29
#define M_ECC_M                   30
#define M_ECC_Q                   31
#define M_ECC_H                   32
#define M_ECC_4STATE              34

#define M_ENC_NUM                          0   // These numbers are importants!!
#define M_ENC_ALPHA                        1
#define M_ENC_ALPHANUM_PUNC                2
#define M_ENC_ALPHANUM                     3
#define M_ENC_ASCII                        4
#define M_ENC_ISO8                         5
#define M_ENC_MODE2                        6
#define M_ENC_MODE3                        (M_ENC_MODE2 + 1)
#define M_ENC_MODE4                        (M_ENC_MODE2 + 2)
#define M_ENC_MODE5                        (M_ENC_MODE2 + 3)
#define M_ENC_MODE6                        (M_ENC_MODE2 + 4)
#define M_ENC_STANDARD                     11
#define M_ENC_EAN13                        0x00000020 //32 
#define M_ENC_EAN8                         0x00000040 //64
#define M_ENC_UPCA                         0x00000080 //128
#define M_ENC_UPCE                         0x00000100 //256
#if OldDefinesSupport
   #define M_ENC_UCCEAN128_PDF417          0x00000200 //512
   #define M_ENC_RSS14                     0x00000400 //1024
   #define M_ENC_RSS14_TRUNCATED           0x00000800 //2048
   #define M_ENC_RSS_LIMITED               0x00001000 //4096
   #define M_ENC_RSS_EXPANDED              0x00002000 //8192
   #define M_ENC_RSS14_STACKED             0x00004000 //16384
   #define M_ENC_RSS14_STACKED_OMNI        0x00008000 //32768
   #define M_ENC_RSS_EXPANDED_STACKED      0x00010000 //65536
   #define M_ENC_UCCEAN128_MICROPDF417     0x00020000 //131072
   #define M_ENC_UCCEAN128                 0x00040000 //262144
   #define M_ENC_GS1_128                   0x00040000
   MIL_DEPRECATED(M_ENC_UCCEAN128_PDF417     , 1010)
   MIL_DEPRECATED(M_ENC_RSS14                , 1010)
   MIL_DEPRECATED(M_ENC_RSS14_TRUNCATED      , 1010)
   MIL_DEPRECATED(M_ENC_RSS_LIMITED          , 1010)
   MIL_DEPRECATED(M_ENC_RSS_EXPANDED         , 1010)
   MIL_DEPRECATED(M_ENC_RSS14_STACKED        , 1010)
   MIL_DEPRECATED(M_ENC_RSS14_STACKED_OMNI   , 1010)
   MIL_DEPRECATED(M_ENC_RSS_EXPANDED_STACKED , 1010)
   MIL_DEPRECATED(M_ENC_UCCEAN128_MICROPDF417, 1010)
   MIL_DEPRECATED(M_ENC_UCCEAN128            , 1010)
   MIL_DEPRECATED(M_ENC_GS1_128              , 1010)
#endif

#define M_ENC_GS1_128_PDF417               0x00000200
#define M_ENC_GS1_DATABAR_OMNI             0x00000400
#define M_ENC_GS1_DATABAR_TRUNCATED        0x00000800
#define M_ENC_GS1_DATABAR_LIMITED          0x00001000
#define M_ENC_GS1_DATABAR_EXPANDED         0x00002000
#define M_ENC_GS1_DATABAR_STACKED          0x00004000
#define M_ENC_GS1_DATABAR_STACKED_OMNI     0x00008000
#define M_ENC_GS1_DATABAR_EXPANDED_STACKED 0x00010000
#define M_ENC_GS1_128_MICROPDF417          0x00020000


#define M_ENC_QRCODE_MODEL1          0x00200000 //2097152
#define M_ENC_QRCODE_MODEL2          0x00400000 //4194304

// 4-State encoding
#define M_ENC_US_MAIL                14
#define M_ENC_UK_MAIL                15
#define M_ENC_AUSTRALIA_MAIL_RAW     16
#define M_ENC_AUSTRALIA_MAIL_C       17
#define M_ENC_AUSTRALIA_MAIL_N       18
#define M_ENC_KOREA_MAIL             19
// AddOn encoding
#define M_ENC_UPCA_ADDON             20
#define M_ENC_UPCE_ADDON             21
#define M_ENC_EAN13_ADDON            22
#define M_ENC_EAN8_ADDON             23

// Aztec encoding
#define M_ENC_AZTEC_COMPACT          24 
#define M_ENC_AZTEC_FULL_RANGE       25
#define M_ENC_AZTEC_RUNE             26

#define M_STATUS_READ_OK               0
#define M_STATUS_CRC_FAILED            1
#define M_STATUS_ECC_UNKNOWN           2
#define M_STATUS_ENC_UNKNOWN           3
#define M_STATUS_WRITE_OK              4  
#define M_STATUS_WRITE_FAILED          5
#define M_STATUS_NOT_FOUND             6
#define M_STATUS_GRADE_OK              7
#define M_STATUS_GRADE_FAILED          8
#if OldDefinesSupport
   #define M_STATUS_VERIFY_OK          M_STATUS_GRADE_OK       //obsolete flag, kept for legacy purpose
   #define M_STATUS_VERIFY_FAILED      M_STATUS_GRADE_FAILED   //obsolete flag, kept for legacy purpose
   MIL_DEPRECATED(M_STATUS_VERIFY_OK    , 1010)
   MIL_DEPRECATED(M_STATUS_VERIFY_FAILED, 1010)
#endif
#define M_STATUS_NO_RESULT_AVAILABLE   9
#define M_STATUS_TIMEOUT_END           10
#define M_STATUS_ENCODING_ERROR        11

#define M_VERY_LOW               0L   // Already define as 0L
#define M_LOW                    1L   // Already define as 1L
#define M_MEDIUM                 2L   // Already define as 2L
#define M_HIGH                   3L   // Already define as 3L
#define M_VERY_HIGH              4L   // Already define as 4L


#define M_ISO_GRADING        0x00000010L
#define M_AIMDPM_GRADING     0x00000080L

#if OldDefinesSupport
   #define M_ISO_VERIFICATION        M_ISO_GRADING
   #define M_ANSI_VERIFICATION       0x00000020L   
   #define M_LEGACY_VERIFICATION     0x00000040L
   #define M_AIMDPM_VERIFICATION     M_AIMDPM_GRADING
   MIL_DEPRECATED(M_ISO_VERIFICATION   , 1010)
   MIL_DEPRECATED(M_ANSI_VERIFICATION  , 1010)
   MIL_DEPRECATED(M_LEGACY_VERIFICATION, 1010)
   MIL_DEPRECATED(M_AIMDPM_VERIFICATION, 1010)
#endif

#define M_ANY                     0x11000000L      // Already define as 0x11000000L
#define M_DEFAULT                 0x10000000L      // Already define as 0x10000000L

#define M_PRESENT                          2L      // Already define as 2L
#define M_ABSENT                           3L

#define M_REGULAR                 0x00020000L      // Already define as 0x00020000L

#define M_RELATIVE                21L              // Already defined in milcolor.h 
#define M_ABSOLUTE                1L               // Already defined in milpat.h

// Threshold modes
#define M_ADAPTIVE                                  2048L // already defined in mil.h
#define M_USER_DEFINED                                21L // Defined in mil.h ; not actual threshold mode
#define M_GLOBAL_SEGMENTATION              M_USER_DEFINED // Must be equal to M_USER_DEFINED for API uniformity with milstr.
#define M_GLOBAL_WITH_LOCAL_RESEGMENTATION    0x00001000L // equals 4096L
// Threshold-specific values
#define M_AUTO_COMPUTE                        0x08000001L // already defined in milstr.h

//Grading result possible values
#define M_CODE_GRADE_A              4L //These numbers should not be changed
#define M_CODE_GRADE_B              3L
#define M_CODE_GRADE_C              2L
#define M_CODE_GRADE_D              1L
#define M_CODE_GRADE_F              0L
#define M_CODE_GRADE_NOT_AVAILABLE  5L

// String format
#define M_AUTO_FORMAT               0x00000080L
#define M_UPCE_COMPRESSED           0x00000081L
#define M_GS1_HUMAN_READABLE        0x00000082L

#define M_SIMPLIFIED_CHINESE        0x00000086L
#define M_JAPANESE                  0x00000088L
#define M_LATIN                     0x00000090L
#define M_KOREAN                    0x00000092L 

#define M_GS1_RAW_DATA       0x00000094L

/**************************************************************************/
/* McodeDraw() parameter values                                           */
/**************************************************************************/
#define M_DRAW_SCAN_PROFILES        0x00000001L
#define M_DRAW_REFLECTANCE_PROFILE  0x00000002L
#define M_DRAW_BOX                  0x00000020L    // Already define as 0x00000020L
#define M_DRAW_POSITION             0x00000040L    // Already define as 0x00000040L
#define M_DRAW_CODE                 0x00000080L
#define M_DRAW_QUIET_ZONE           0x00001000L    // Should be bitwise also with M_LINEAR_COMPONENT and M_2D_COMPONENT
#define M_DRAW_EXTENDED_AREA        0x00002000L    // Should be bitwise also with M_LINEAR_COMPONENT and M_2D_COMPONENT


/**************************************************************************/
/* Function prototypes                                                    */
/**************************************************************************/

MIL_CODE_DLLFUNC MIL_ID MFTYPE McodeAlloc(MIL_ID SysId, MIL_INT64  ContextType, MIL_INT64  ControlFlag, MIL_ID *ContextCodeIdPtr);

#if M_MIL_USE_64BIT
// Prototypes for 64 bits OSs
MIL_CODE_DLLFUNC void   MFTYPE McodeControlInt64   (MIL_ID ContextOrResultCodeId, MIL_INT64  ControlType, MIL_INT64 ControlValue);
MIL_CODE_DLLFUNC void   MFTYPE McodeControlDouble  (MIL_ID ContextOrResultCodeId, MIL_INT64  ControlType, MIL_DOUBLE ControlValue);
#else
// Prototypes for 32 bits OSs
#define McodeControlInt64  McodeControl
#define McodeControlDouble McodeControl
MIL_CODE_DLLFUNC void   MFTYPE McodeControl   (MIL_ID ContextOrResultCodeId, MIL_INT64  ControlType, MIL_DOUBLE ControlValue);
#endif

MIL_CODE_DLLFUNC MIL_INT   MFTYPE McodeInquire       (MIL_ID ContextOrResultCodeId, MIL_INT64  InquireType, void *UserVarPtr);
MIL_CODE_DLLFUNC void   MFTYPE McodeRead             (MIL_ID ContextCodeId, MIL_ID ImageBufId, MIL_ID ResultCodeId);
MIL_CODE_DLLFUNC void   MFTYPE McodeGetResult        (MIL_ID ResultCodeId, MIL_INT64  ResultType, void *UserVarArrayPtr);
MIL_CODE_DLLFUNC void   MFTYPE McodeGetResultSingle  (MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, void *UserVarPtr);
MIL_CODE_DLLFUNC MIL_ID MFTYPE McodeModel            (MIL_ID ContextCodeId, MIL_INT64  Operation, MIL_INT64  CodeType, MIL_INT Instance, MIL_INT64  ControlFlag, MIL_ID* ModelCodeIdPtr);
MIL_CODE_DLLFUNC void   MFTYPE McodeFree             (MIL_ID ContextOrResultCodeId);
MIL_CODE_DLLFUNC MIL_ID MFTYPE McodeAllocResult      (MIL_ID SysId, MIL_INT64  ControlFlag, MIL_ID *ResultCodeIdPtr);
MIL_CODE_DLLFUNC void   MFTYPE McodeDraw             (MIL_ID ContextGraId, MIL_ID ResultCodeId, MIL_ID DstImageBufOrListGraId, MIL_INT64  Operation, MIL_INT ResultIndex, MIL_INT64 ControlFlag);
MIL_CODE_DLLFUNC void   MFTYPE McodeGrade            (MIL_ID ContextCodeId, MIL_ID ImageBufId, MIL_ID SrcResultCodeId, MIL_INT SrcModelCodeIndexOrResultIndex, MIL_ID DstResultCodeId, MIL_INT64  ControlFlag);

#if M_MIL_USE_UNICODE
MIL_CODE_DLLFUNC void   MFTYPE McodeSaveA      (const char* FileName, MIL_ID ContextCodeId, MIL_INT64  ControlFlag);
MIL_CODE_DLLFUNC MIL_ID MFTYPE McodeRestoreA   (const char* FileName, MIL_ID SysId, MIL_INT64  ControlFlag, MIL_ID* ContextCodeIdPtr);
MIL_CODE_DLLFUNC void   MFTYPE McodeStreamA    (char* MemPtrOrFileName, MIL_ID SysId, MIL_INT64  Operation, MIL_INT64  StreamType,
                                            MIL_DOUBLE Version, MIL_INT64  ControlFlag, MIL_ID *ContextOrResultCodeIdPtr, MIL_INT   *SizeByteVarPtr);
MIL_CODE_DLLFUNC void   MFTYPE McodeVerifyA    (MIL_ID CodeContextId, MIL_ID ImageBufId, const char* String, MIL_ID CodeResultId);
MIL_CODE_DLLFUNC void   MFTYPE McodeWriteA     (MIL_ID ModelCodeId, MIL_ID ImageBufId, const char* StringPtr, MIL_INT64  ControlFlag);

MIL_CODE_DLLFUNC void   MFTYPE McodeSaveW      (MIL_CONST_TEXT_PTR FileName, MIL_ID ContextCodeId, MIL_INT64  ControlFlag);
MIL_CODE_DLLFUNC MIL_ID MFTYPE McodeRestoreW   (MIL_CONST_TEXT_PTR FileName, MIL_ID SysId, MIL_INT64  ControlFlag, MIL_ID* ContextCodeIdPtr);
MIL_CODE_DLLFUNC void   MFTYPE McodeStreamW    (MIL_TEXT_PTR MemPtrOrFileName, MIL_ID SysId, MIL_INT64  Operation, MIL_INT64  StreamType,
                                            MIL_DOUBLE Version, MIL_INT64  ControlFlag, MIL_ID *ContextOrResultCodeIdPtr, MIL_INT   *SizeByteVarPtr);
MIL_CODE_DLLFUNC void   MFTYPE McodeVerifyW    (MIL_ID CodeContextId, MIL_ID ImageBufId, MIL_CONST_TEXT_PTR String, MIL_ID CodeResultId);
MIL_CODE_DLLFUNC void   MFTYPE McodeWriteW     (MIL_ID ModelCodeId, MIL_ID ImageBufId, MIL_CONST_TEXT_PTR StringPtr, MIL_INT64  ControlFlag);

#if M_MIL_UNICODE_API
#define McodeSave           McodeSaveW
#define McodeRestore        McodeRestoreW
#define McodeStream         McodeStreamW
#define McodeVerify         McodeVerifyW
#define McodeWrite          McodeWriteW
#else
#define McodeSave           McodeSaveA
#define McodeRestore        McodeRestoreA
#define McodeStream         McodeStreamA
#define McodeVerify         McodeVerifyA
#define McodeWrite          McodeWriteA
#endif

#else
MIL_CODE_DLLFUNC void   MFTYPE McodeSave      (MIL_CONST_TEXT_PTR FileName, MIL_ID ContextCodeId, MIL_INT64  ControlFlag);
MIL_CODE_DLLFUNC MIL_ID MFTYPE McodeRestore   (MIL_CONST_TEXT_PTR FileName, MIL_ID SysId, MIL_INT64  ControlFlag, MIL_ID* ContextCodeIdPtr );
MIL_CODE_DLLFUNC void   MFTYPE McodeStream    (MIL_TEXT_PTR MemPtrOrFileName, MIL_ID SysId, MIL_INT64  Operation, MIL_INT64  StreamType,
                                               MIL_DOUBLE Version, MIL_INT64  ControlFlag, MIL_ID *ContextOrResultCodeIdPtr, MIL_INT   *SizeByteVarPtr );
MIL_CODE_DLLFUNC void   MFTYPE McodeVerify    (MIL_ID CodeContextId, MIL_ID ImageBufId, MIL_CONST_TEXT_PTR String, MIL_ID CodeResultId);
MIL_CODE_DLLFUNC void   MFTYPE McodeWrite     (MIL_ID ModelCodeId, MIL_ID ImageBufId, MIL_CONST_TEXT_PTR StringPtr, MIL_INT64  ControlFlag);
#endif

/* C++ directive if needed */
#ifdef __cplusplus
}
#endif

#if M_MIL_USE_64BIT
#ifdef __cplusplus
//////////////////////////////////////////////////////////////
// McodeControl function definition when compiling c++ files
//////////////////////////////////////////////////////////////
#if !M_MIL_USE_LINUX
inline void McodeControl(MIL_ID ContextOrResultCodeId, MIL_INT64  ControlType, int ControlValue)
   {
   McodeControlInt64(ContextOrResultCodeId, ControlType, ControlValue);
   };
#endif
inline void McodeControl(MIL_ID ContextOrResultCodeId, MIL_INT64  ControlType, MIL_INT32 ControlValue)
   {
   McodeControlInt64(ContextOrResultCodeId, ControlType, ControlValue);
   };
inline void McodeControl(MIL_ID ContextOrResultCodeId, MIL_INT64  ControlType, MIL_INT64 ControlValue)
   {
   McodeControlInt64(ContextOrResultCodeId, ControlType, ControlValue);
   };
inline void McodeControl(MIL_ID ContextOrResultCodeId, MIL_INT64  ControlType, MIL_DOUBLE ControlValue)
   {
   McodeControlDouble(ContextOrResultCodeId, ControlType, ControlValue);
   };

#else
//////////////////////////////////////////////////////////////
// For C file, call the default function, i.e. Int64 one
//////////////////////////////////////////////////////////////
#define McodeControl  McodeControlDouble

#endif // __cplusplus
#endif // M_MIL_USE_64BIT

#if M_MIL_USE_SAFE_TYPE

//////////////////////////////////////////////////////////////
// See milos.h for explanation about these functions.
//////////////////////////////////////////////////////////////

// ----------------------------------------------------------
// McodeGetResult

inline void   MFTYPE McodeGetResultUnsafe  (MIL_ID ResultCodeId, MIL_INT64  ResultType, void        *UserVarArrayPtr);
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, int          UserVarArrayPtr);
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_INT8    *UserVarArrayPtr);
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_INT16   *UserVarArrayPtr);
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_INT32   *UserVarArrayPtr);
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_INT64   *UserVarArrayPtr);
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, float       *UserVarArrayPtr);
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_DOUBLE  *UserVarArrayPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                      
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_UINT8   *UserVarArrayPtr);
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_UINT16  *UserVarArrayPtr);
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_UINT32  *UserVarArrayPtr);
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_UINT64  *UserVarArrayPtr);
#endif                                                     
#if M_MIL_SAFE_TYPE_ADD_WCHAR_T                            
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, wchar_t     *UserVarArrayPtr);
#endif

// ----------------------------------------------------------
// McodeGetResultSingle

inline void   MFTYPE McodeGetResultSingleUnsafe  (MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, void        *UserVarPtr);
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, int          UserVarPtr);
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_INT8    *UserVarPtr);
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_INT16   *UserVarPtr);
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_INT32   *UserVarPtr);
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_INT64   *UserVarPtr);
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, float       *UserVarPtr);
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_DOUBLE  *UserVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                                                 
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_UINT8   *UserVarPtr);
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_UINT16  *UserVarPtr);
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_UINT32  *UserVarPtr);
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_UINT64  *UserVarPtr);
#endif                                                                                
#if M_MIL_SAFE_TYPE_ADD_WCHAR_T                                                       
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, wchar_t     *UserVarPtr);
#endif

// ----------------------------------------------------------
// McodeInquire

inline MIL_INT MFTYPE McodeInquireUnsafe  (MIL_ID ContextOrResultCodeId, MIL_INT64  InquireType, void        * UserVarPtr);
inline MIL_INT MFTYPE McodeInquireSafeType(MIL_ID ContextOrResultCodeId, MIL_INT64  InquireType, int           UserVarPtr);
inline MIL_INT MFTYPE McodeInquireSafeType(MIL_ID ContextOrResultCodeId, MIL_INT64  InquireType, MIL_INT32   * UserVarPtr);
inline MIL_INT MFTYPE McodeInquireSafeType(MIL_ID ContextOrResultCodeId, MIL_INT64  InquireType, MIL_INT64   * UserVarPtr);
inline MIL_INT MFTYPE McodeInquireSafeType(MIL_ID ContextOrResultCodeId, MIL_INT64  InquireType, MIL_DOUBLE  * UserVarPtr);
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                     
inline MIL_INT MFTYPE McodeInquireSafeType(MIL_ID ContextOrResultCodeId, MIL_INT64  InquireType, MIL_UINT32  * UserVarPtr);
inline MIL_INT MFTYPE McodeInquireSafeType(MIL_ID ContextOrResultCodeId, MIL_INT64  InquireType, MIL_UINT64  * UserVarPtr);
#endif

// ----------------------------------------------------------
// McodeGetResult

inline MIL_INT64  McodeGetResultRequiredType(MIL_INT64  ResultType)
   {
   switch (ResultType)
      {
      case M_STRING:
      case M_STRING+M_ESCAPE_SEQUENCE:
         return M_TYPE_TEXT_CHAR;
         break;

      default:
         return M_TYPE_DOUBLE;
         break;
      }
   }

inline void MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, int UserVarArrayPtr)
   {
   if (UserVarArrayPtr)
      SafeTypeError(MIL_TEXT("McodeGetResult"));

   McodeGetResult(ResultCodeId, ResultType, NULL);
   }

inline void McodeGetResultSafeTypeExecute(MIL_ID ResultCodeId, MIL_INT64  ResultType, void        *UserVarArrayPtr, MIL_INT64  GivenType)
   {
   MIL_INT64  RequiredType = (ResultType & M_HLVLDATATYPE_MASK);
   if((RequiredType != M_TYPE_DOUBLE) && (RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) && 
      (RequiredType != M_TYPE_MIL_ID) && (RequiredType != M_TYPE_FLOAT) && (RequiredType != M_TYPE_CHAR) && 
      (RequiredType != M_TYPE_SHORT) && (RequiredType != M_TYPE_TEXT_CHAR))
      RequiredType = 0;
   if (RequiredType == 0)
      RequiredType = McodeGetResultRequiredType(ResultType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MIL_TEXT("McodeGetResult"));

   McodeGetResult(ResultCodeId, ResultType, UserVarArrayPtr);
   }

inline void   MFTYPE McodeGetResultUnsafe  (MIL_ID ResultCodeId, MIL_INT64  ResultType, void          *UserVarArrayPtr) { McodeGetResult(ResultCodeId, ResultType, UserVarArrayPtr); }
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_INT8      *UserVarArrayPtr) { McodeGetResultSafeTypeExecute(ResultCodeId, ResultType, UserVarArrayPtr, M_TYPE_CHAR); }
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_INT16     *UserVarArrayPtr) { McodeGetResultSafeTypeExecute(ResultCodeId, ResultType, UserVarArrayPtr, M_TYPE_SHORT); }
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_INT32     *UserVarArrayPtr) { McodeGetResultSafeTypeExecute(ResultCodeId, ResultType, UserVarArrayPtr, M_TYPE_MIL_INT32); }
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_INT64     *UserVarArrayPtr) { McodeGetResultSafeTypeExecute(ResultCodeId, ResultType, UserVarArrayPtr, M_TYPE_MIL_INT64); }
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, float         *UserVarArrayPtr) { McodeGetResultSafeTypeExecute(ResultCodeId, ResultType, UserVarArrayPtr, M_TYPE_FLOAT); }
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_DOUBLE    *UserVarArrayPtr) { McodeGetResultSafeTypeExecute(ResultCodeId, ResultType, UserVarArrayPtr, M_TYPE_DOUBLE); }
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_UINT8     *UserVarArrayPtr) { McodeGetResultSafeTypeExecute(ResultCodeId, ResultType, UserVarArrayPtr, M_TYPE_CHAR); }
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_UINT16    *UserVarArrayPtr) { McodeGetResultSafeTypeExecute(ResultCodeId, ResultType, UserVarArrayPtr, M_TYPE_SHORT); }
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_UINT32    *UserVarArrayPtr) { McodeGetResultSafeTypeExecute(ResultCodeId, ResultType, UserVarArrayPtr, M_TYPE_MIL_INT32); }
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, MIL_UINT64    *UserVarArrayPtr) { McodeGetResultSafeTypeExecute(ResultCodeId, ResultType, UserVarArrayPtr, M_TYPE_MIL_INT64); }
#endif                                                     
#if M_MIL_SAFE_TYPE_ADD_WCHAR_T                            
inline void   MFTYPE McodeGetResultSafeType(MIL_ID ResultCodeId, MIL_INT64  ResultType, wchar_t       *UserVarArrayPtr) { McodeGetResultSafeTypeExecute(ResultCodeId, ResultType, UserVarArrayPtr, M_TYPE_MIL_TEXT); }
#endif

// ----------------------------------------------------------
// McodeGetResultSingle

inline void MFTYPE McodeGetResultSingleSafeType (MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, int UserVarPtr)
   {
   if (UserVarPtr)
      SafeTypeError(MIL_TEXT("McodeGetResultSingle"));

   McodeGetResultSingle(ResultCodeId, ResultIndex, ResultType, NULL);
   }

inline void MFTYPE McodeGetResultSingleSafeTypeExecute (MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, void        *UserVarPtr, MIL_INT64  GivenType)
   {
   MIL_INT64  RequiredType = (ResultType & M_HLVLDATATYPE_MASK);
   if((RequiredType != M_TYPE_DOUBLE) && (RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) && 
      (RequiredType != M_TYPE_MIL_ID) && (RequiredType != M_TYPE_FLOAT) && (RequiredType != M_TYPE_CHAR) && 
      (RequiredType != M_TYPE_SHORT) && (RequiredType != M_TYPE_TEXT_CHAR))
      RequiredType = 0;
   if (RequiredType == 0)
      RequiredType = McodeGetResultRequiredType(ResultType);
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MIL_TEXT("McodeGetResultSingle"));

   McodeGetResultSingle(ResultCodeId, ResultIndex,ResultType, UserVarPtr);
   }

inline void   MFTYPE McodeGetResultSingleUnsafe  (MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, void          *UserVarPtr) {McodeGetResultSingle(ResultCodeId, ResultIndex, ResultType, UserVarPtr);}
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_INT8      *UserVarPtr) {McodeGetResultSingleSafeTypeExecute(ResultCodeId, ResultIndex, ResultType, UserVarPtr, M_TYPE_CHAR     );}
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_INT16     *UserVarPtr) {McodeGetResultSingleSafeTypeExecute(ResultCodeId, ResultIndex, ResultType, UserVarPtr, M_TYPE_SHORT    );}
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_INT32     *UserVarPtr) {McodeGetResultSingleSafeTypeExecute(ResultCodeId, ResultIndex, ResultType, UserVarPtr, M_TYPE_MIL_INT32);}
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_INT64     *UserVarPtr) {McodeGetResultSingleSafeTypeExecute(ResultCodeId, ResultIndex, ResultType, UserVarPtr, M_TYPE_MIL_INT64);}
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, float         *UserVarPtr) {McodeGetResultSingleSafeTypeExecute(ResultCodeId, ResultIndex, ResultType, UserVarPtr, M_TYPE_FLOAT    );}
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_DOUBLE    *UserVarPtr) {McodeGetResultSingleSafeTypeExecute(ResultCodeId, ResultIndex, ResultType, UserVarPtr, M_TYPE_DOUBLE   );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                                                 
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_UINT8     *UserVarPtr) {McodeGetResultSingleSafeTypeExecute(ResultCodeId, ResultIndex, ResultType, UserVarPtr, M_TYPE_CHAR     );}
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_UINT16    *UserVarPtr) {McodeGetResultSingleSafeTypeExecute(ResultCodeId, ResultIndex, ResultType, UserVarPtr, M_TYPE_SHORT    );}
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_UINT32    *UserVarPtr) {McodeGetResultSingleSafeTypeExecute(ResultCodeId, ResultIndex, ResultType, UserVarPtr, M_TYPE_MIL_INT32);}
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, MIL_UINT64    *UserVarPtr) {McodeGetResultSingleSafeTypeExecute(ResultCodeId, ResultIndex, ResultType, UserVarPtr, M_TYPE_MIL_INT64);}
#endif                                                                                
#if M_MIL_SAFE_TYPE_ADD_WCHAR_T                                                       
inline void   MFTYPE McodeGetResultSingleSafeType(MIL_ID ResultCodeId, MIL_INT ResultIndex, MIL_INT64  ResultType, wchar_t       *UserVarPtr) {McodeGetResultSingleSafeTypeExecute(ResultCodeId, ResultIndex, ResultType, UserVarPtr, M_TYPE_MIL_TEXT    );}
#endif

// ----------------------------------------------------------

// McodeInquire

inline MIL_INT MFTYPE McodeInquireSafeType(MIL_ID ContextOrResultCodeId, MIL_INT64  InquireType, int UserVarPtr)
   {
   if (UserVarPtr)
      SafeTypeError(MIL_TEXT("McodeInquire"));

   return McodeInquire(ContextOrResultCodeId, InquireType, NULL);
   }

inline MIL_INT MFTYPE McodeInquireSafeTypeExecute (MIL_ID ContextOrResultCodeId, MIL_INT64  InquireType, void  *UserVarPtr, MIL_INT64  GivenType)
   {
   MIL_INT64  RequiredType = (InquireType & M_HLVLDATATYPE_MASK);
   if((RequiredType != M_TYPE_MIL_INT32) && (RequiredType != M_TYPE_MIL_INT64) && (RequiredType != M_TYPE_MIL_DOUBLE) && (RequiredType != M_TYPE_MIL_ID))
      RequiredType = 0;
   if (RequiredType == 0)
      RequiredType = M_TYPE_DOUBLE;
   ReplaceTypeMilIdByTypeMilIntXX(&RequiredType);

   if (RequiredType != GivenType)
      SafeTypeError(MIL_TEXT("McodeInquire"));

   return McodeInquire(ContextOrResultCodeId, InquireType, UserVarPtr);
   }

inline MIL_INT MFTYPE McodeInquireUnsafe  (MIL_ID ContextOrResultCodeId, MIL_INT64  InquireType, void        * UserVarPtr) {return McodeInquire               (ContextOrResultCodeId, InquireType, UserVarPtr                  );}
inline MIL_INT MFTYPE McodeInquireSafeType(MIL_ID ContextOrResultCodeId, MIL_INT64  InquireType, MIL_INT32   * UserVarPtr) {return McodeInquireSafeTypeExecute(ContextOrResultCodeId, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MIL_INT MFTYPE McodeInquireSafeType(MIL_ID ContextOrResultCodeId, MIL_INT64  InquireType, MIL_INT64   * UserVarPtr) {return McodeInquireSafeTypeExecute(ContextOrResultCodeId, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
inline MIL_INT MFTYPE McodeInquireSafeType(MIL_ID ContextOrResultCodeId, MIL_INT64  InquireType, MIL_DOUBLE  * UserVarPtr) {return McodeInquireSafeTypeExecute(ContextOrResultCodeId, InquireType, UserVarPtr, M_TYPE_DOUBLE   );}
#if M_MIL_SAFE_TYPE_SUPPORTS_UNSIGNED                     
inline MIL_INT MFTYPE McodeInquireSafeType(MIL_ID ContextOrResultCodeId, MIL_INT64  InquireType, MIL_UINT32  * UserVarPtr) {return McodeInquireSafeTypeExecute(ContextOrResultCodeId, InquireType, UserVarPtr, M_TYPE_MIL_INT32);}
inline MIL_INT MFTYPE McodeInquireSafeType(MIL_ID ContextOrResultCodeId, MIL_INT64  InquireType, MIL_UINT64  * UserVarPtr) {return McodeInquireSafeTypeExecute(ContextOrResultCodeId, InquireType, UserVarPtr, M_TYPE_MIL_INT64);}
#endif

#define McodeGetResult       McodeGetResultSafeType
#define McodeGetResultSingle McodeGetResultSingleSafeType
#define McodeInquire         McodeInquireSafeType

#else // #if M_MIL_USE_SAFE_TYPE

#define McodeGetResultUnsafe       McodeGetResult
#define McodeGetResultSingleUnsafe McodeGetResultSingle
#define McodeInquireUnsafe         McodeInquire

#endif // #if M_MIL_USE_SAFE_TYPE

#endif // !M_MIL_LITE

#endif /* __MILCODE_H__ */
