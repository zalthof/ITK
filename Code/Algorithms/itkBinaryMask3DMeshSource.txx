/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkBinaryMask3DMeshSource.txx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef _itkBinaryMask3DMeshSource_txx
#define _itkBinaryMask3DMeshSource_txx

#include "itkBinaryMask3DMeshSource.h"

namespace itk
{

template<class TOutputMesh>
BinaryMask3DMeshSource<TOutputMesh>
::BinaryMask3DMeshSource()
{
  m_NumberOfCells = 0;
  m_NumberOfNodes = 0;

  /** Create the output. */
  typename TOutputMesh::Pointer output = TOutputMesh::New();
  this->ProcessObject::SetNumberOfRequiredOutputs(1);
  this->ProcessObject::SetNthOutput(0, output.GetPointer());

  m_NodeLimit = 2000;
  m_CellLimit = 4000;
  m_LastRowIndex = 0;
  m_LastVoxelIndex = 0;
  m_LastFrameIndex = 0;
  m_CurrentRowIndex = 0;
  m_CurrentFrameIndex = 0;
  m_LastRowNum = 0;
  m_LastFrameNum = 0;
  m_CurrentRowNum = 200;
  m_CurrentFrameNum = 2000;
  this->GetOutput()->GetPoints()->Reserve(m_NodeLimit);
//  this->GetOutput()->GetCells()->Reserve(m_CellLimit);

}

template<class TOutputMesh>
void
BinaryMask3DMeshSource<TOutputMesh>
::GenerateData()
{
  this->InitializeLUT();
  this->CreateMesh();
  std::cout << "end" << std::endl;
//  this->GetOutput()->GetPoints()->Reserve(m_NumberOfNodes);
//  this->GetOutput()->GetCells()->Reserve(m_NumberOfCells);
}

template<class TOutputMesh>
void
BinaryMask3DMeshSource<TOutputMesh>
::XFlip(unsigned char *x)
{
  unsigned char nodeindex;
  
  int i=0; 

  while ( i < 3 ) {
    nodeindex = x[i];
    switch ( (int)nodeindex ) {
      case 1:
        break;
      case 2:
        x[i] = 4;
        break;        
      case 3:
        break;
      case 4:
        x[i] = 2;
        break;
      case 5:
        break;
      case 6:
        x[i] = 8;
        break;
      case 7:
        break;
      case 8:
        x[i] = 6;
        break;
      case 9:
        x[i] = 10;
        break;
      case 10:
        x[i] = 9;
        break;
      case 11:
        x[i] = 12;
        break;
      case 12:
        x[i] = 11;
        break;
      case 13:
        break;
    }
    i++;
  }
}

template<class TOutputMesh>
void
BinaryMask3DMeshSource<TOutputMesh>
::YFlip(unsigned char *x)
{
  unsigned char nodeindex;
  
  int i=0; 

  while ( i < 3 ) {
    nodeindex = x[i];
    switch ( (int)nodeindex ) {
      case 1:
        x[i] = 3;
        break;
      case 2:
        break;        
      case 3:
        x[i] = 1;
        break;
      case 4:
        break;
      case 5:
        x[i] = 7;
        break;
      case 6:
        break;
      case 7:
        x[i] = 5;
        break;
      case 8:
        break;
      case 9:
        x[i] = 12;
        break;
      case 10:
        x[i] = 11;
        break;
      case 11:
        x[i] = 10;
        break;
      case 12:
        x[i] = 9;
        break;
      case 13:
        break;
    }
    i++;
  }
}

template<class TOutputMesh>
void
BinaryMask3DMeshSource<TOutputMesh>
::ZFlip(unsigned char *x)
{
  unsigned char nodeindex;
  
  int i=0; 

  while ( i < 3 ) {
    nodeindex = x[i];
    switch ( (int)nodeindex ) {
      case 1:
        x[i] = 5;
        break;
      case 2:
        x[i] = 6;
        break;        
      case 3:
        x[i] = 7;
        break;
      case 4:
        x[i] = 8;
        break;
      case 5:
        x[i] = 1;
        break;
      case 6:
        x[i] = 2;
        break;
      case 7:
        x[i] = 3;
        break;
      case 8:
        x[i] = 4;
        break;
      case 9:
        break;
      case 10:
        break;
      case 11:
        break;
      case 12:
        break;
      case 13:
        break;
    }
    i++;
  }
}

template<class TOutputMesh>
void
BinaryMask3DMeshSource<TOutputMesh>
::XRotation(unsigned char *x)
{
  unsigned char nodeindex;
  
  int i=0; 

  while ( i<3 ) {
    nodeindex = x[i];
    switch ( (int)nodeindex ) {
      case 1:
        x[i] = 4;
        break;
      case 2:
        x[i] = 1;
        break;        
      case 3:
        x[i] = 2;
        break;
      case 4:
        x[i] = 3;
        break;
      case 5:
        x[i] = 8;
        break;
      case 6:
        x[i] = 5;
        break;
      case 7:
        x[i] = 6;
        break;
      case 8:
        x[i] = 7;
        break;
      case 9:
        x[i] = 12;
        break;
      case 10:
        x[i] = 9;
        break;
      case 11:
        x[i] = 10;
        break;
      case 12:
        x[i] = 11;
        break;
      case 13:
        break;
    }
    i++;
  }
}

template<class TOutputMesh>
void
BinaryMask3DMeshSource<TOutputMesh>
::YRotation(unsigned char *x)
{
  unsigned char nodeindex;
  
  int i=0; 

  while ( i<3 ) {
    nodeindex = x[i];
    switch ( (int)nodeindex ) {
      case 1:
        x[i] = 9;
        break;
      case 2:
        x[i] = 4;
        break;        
      case 3:
        x[i] = 12;
        break;
      case 4:
        x[i] = 8;
        break;
      case 5:
        x[i] = 10;
        break;
      case 6:
        x[i] = 2;
        break;
      case 7:
        x[i] = 11;
        break;
      case 8:
        x[i] = 6;
        break;
      case 9:
        x[i] = 5;
        break;
      case 10:
        x[i] = 1;
        break;
      case 11:
        x[i] = 3;
        break;
      case 12:
        x[i] = 7;
        break;
      case 13:
        break;
    }
    i++;
  }
}

template<class TOutputMesh>
void
BinaryMask3DMeshSource<TOutputMesh>
::ZRotation(unsigned char *x)
{
  unsigned char nodeindex;
  
  int i=0; 

  while ( i<3 ) {
    nodeindex = x[i];
    switch ( (int)nodeindex ) {
      case 1:
        x[i] = 3;
        break;
      case 2:
        x[i] = 11;
        break;        
      case 3:
        x[i] = 7;
        break;
      case 4:
        x[i] = 12;
        break;
      case 5:
        x[i] = 1;
        break;
      case 6:
        x[i] = 10;
        break;
      case 7:
        x[i] = 5;
        break;
      case 8:
        x[i] = 9;
        break;
      case 9:
        x[i] = 4;
        break;
      case 10:
        x[i] = 2;
        break;
      case 11:
        x[i] = 6;
        break;
      case 12:
        x[i] = 8;
        break;
      case 13:
        break;
    }
    i++;
  }
}

template<class TOutputMesh>
void
BinaryMask3DMeshSource<TOutputMesh>
::inverse(unsigned char *x)
{
  unsigned char tmp;
  tmp = x[2];
  x[2] = x[1];
  x[1] = tmp;
}

template<class TOutputMesh>
void
BinaryMask3DMeshSource<TOutputMesh>
::InitializeLUT()
{
  m_LUT[0][0] = 0;
  m_LUT[1][0] = 1;
  m_LUT[2][0] = 1;
  m_LUT[3][0] = 2;
  m_LUT[4][0] = 1;
  m_LUT[5][0] = 3;
  m_LUT[6][0] = 2;
  m_LUT[7][0] = 5;
  m_LUT[8][0] = 1;
  m_LUT[9][0] = 2;
  m_LUT[10][0] = 3;
  m_LUT[11][0] = 5;
  m_LUT[12][0] = 2;
  m_LUT[13][0] = 5;
  m_LUT[14][0] = 5;
  m_LUT[15][0] = 8;
  m_LUT[16][0] = 1;
  m_LUT[17][0] = 2;
  m_LUT[18][0] = 3;
  m_LUT[19][0] = 5;
  m_LUT[20][0] = 4;
  m_LUT[21][0] = 6;
  m_LUT[22][0] = 6;
  m_LUT[23][0] = 11;
  m_LUT[24][0] = 3;
  m_LUT[25][0] = 5;
  m_LUT[26][0] = 7;
  m_LUT[27][0] = 9;
  m_LUT[28][0] = 6;
  m_LUT[29][0] = 11;
  m_LUT[30][0] = 12;
  m_LUT[31][0] = 5;
  m_LUT[32][0] = 1;
  m_LUT[33][0] = 3;
  m_LUT[34][0] = 2;
  m_LUT[35][0] = 5;
  m_LUT[36][0] = 3;
  m_LUT[37][0] = 7;
  m_LUT[38][0] = 5;
  m_LUT[39][0] = 9;
  m_LUT[40][0] = 4;
  m_LUT[41][0] = 6;
  m_LUT[42][0] = 6;
  m_LUT[43][0] = 11;
  m_LUT[44][0] = 6;
  m_LUT[45][0] = 12;
  m_LUT[46][0] = 11;
  m_LUT[47][0] = 5;
  m_LUT[48][0] = 2;
  m_LUT[49][0] = 5;
  m_LUT[50][0] = 5;
  m_LUT[51][0] = 8;
  m_LUT[52][0] = 6;
  m_LUT[53][0] = 12;
  m_LUT[54][0] = 11;
  m_LUT[55][0] = 5;
  m_LUT[56][0] = 6;
  m_LUT[57][0] = 11;
  m_LUT[58][0] = 12;
  m_LUT[59][0] = 5;
  m_LUT[60][0] = 10;
  m_LUT[61][0] = 16;
  m_LUT[62][0] = 16;
  m_LUT[63][0] = 2;
  m_LUT[64][0] = 1;
  m_LUT[65][0] = 4;
  m_LUT[66][0] = 3;
  m_LUT[67][0] = 6;
  m_LUT[68][0] = 2;
  m_LUT[69][0] = 6;
  m_LUT[70][0] = 5;
  m_LUT[71][0] = 11;
  m_LUT[72][0] = 3;
  m_LUT[73][0] = 6;
  m_LUT[74][0] = 7;
  m_LUT[75][0] = 12;
  m_LUT[76][0] = 5;
  m_LUT[77][0] = 11;
  m_LUT[78][0] = 9;
  m_LUT[79][0] = 5;
  m_LUT[80][0] = 3;
  m_LUT[81][0] = 6;
  m_LUT[82][0] = 7;
  m_LUT[83][0] = 12;
  m_LUT[84][0] = 6;
  m_LUT[85][0] = 10;
  m_LUT[86][0] = 12;
  m_LUT[87][0] = 16;
  m_LUT[88][0] = 7;
  m_LUT[89][0] = 12;
  m_LUT[90][0] = 13;
  m_LUT[91][0] = 14;
  m_LUT[92][0] = 12;
  m_LUT[93][0] = 16;
  m_LUT[94][0] = 14;
  m_LUT[95][0] = 15;
  m_LUT[96][0] = 2;
  m_LUT[97][0] = 6;
  m_LUT[98][0] = 5;
  m_LUT[99][0] = 11;
  m_LUT[100][0] = 5;
  m_LUT[101][0] = 12;
  m_LUT[102][0] = 8;
  m_LUT[103][0] = 5;
  m_LUT[104][0] = 6;
  m_LUT[105][0] = 10;
  m_LUT[106][0] = 12;
  m_LUT[107][0] = 16;
  m_LUT[108][0] = 11;
  m_LUT[109][0] = 16;
  m_LUT[110][0] = 5;
  m_LUT[111][0] = 2;
  m_LUT[112][0] = 5;
  m_LUT[113][0] = 11;
  m_LUT[114][0] = 9;
  m_LUT[115][0] = 5;
  m_LUT[116][0] = 11;
  m_LUT[117][0] = 16;
  m_LUT[118][0] = 5;
  m_LUT[119][0] = 2;
  m_LUT[120][0] = 12;
  m_LUT[121][0] = 16;
  m_LUT[122][0] = 14;
  m_LUT[123][0] = 15;
  m_LUT[124][0] = 16;
  m_LUT[125][0] = 4;
  m_LUT[126][0] = 15;
  m_LUT[127][0] = 1;
  m_LUT[128][0] = 1;
  m_LUT[129][0] = 3;
  m_LUT[130][0] = 4;
  m_LUT[131][0] = 6;
  m_LUT[132][0] = 3;
  m_LUT[133][0] = 7;
  m_LUT[134][0] = 6;
  m_LUT[135][0] = 12;
  m_LUT[136][0] = 2;
  m_LUT[137][0] = 5;
  m_LUT[138][0] = 6;
  m_LUT[139][0] = 11;
  m_LUT[140][0] = 5;
  m_LUT[141][0] = 9;
  m_LUT[142][0] = 11;
  m_LUT[143][0] = 5;
  m_LUT[144][0] = 2;
  m_LUT[145][0] = 5;
  m_LUT[146][0] = 6;
  m_LUT[147][0] = 11;
  m_LUT[148][0] = 6;
  m_LUT[149][0] = 12;
  m_LUT[150][0] = 10;
  m_LUT[151][0] = 16;
  m_LUT[152][0] = 5;
  m_LUT[153][0] = 8;
  m_LUT[154][0] = 12;
  m_LUT[155][0] = 5;
  m_LUT[156][0] = 11;
  m_LUT[157][0] = 5;
  m_LUT[158][0] = 16;
  m_LUT[159][0] = 2;
  m_LUT[160][0] = 3;
  m_LUT[161][0] = 7;
  m_LUT[162][0] = 6;
  m_LUT[163][0] = 12;
  m_LUT[164][0] = 7;
  m_LUT[165][0] = 13;
  m_LUT[166][0] = 12;
  m_LUT[167][0] = 14;
  m_LUT[168][0] = 6;
  m_LUT[169][0] = 12;
  m_LUT[170][0] = 10;
  m_LUT[171][0] = 16;
  m_LUT[172][0] = 12;
  m_LUT[173][0] = 14;
  m_LUT[174][0] = 16;
  m_LUT[175][0] = 15;
  m_LUT[176][0] = 5;
  m_LUT[177][0] = 9;
  m_LUT[178][0] = 11;
  m_LUT[179][0] = 5;
  m_LUT[180][0] = 12;
  m_LUT[181][0] = 14;
  m_LUT[182][0] = 16;
  m_LUT[183][0] = 15;
  m_LUT[184][0] = 11;
  m_LUT[185][0] = 5;
  m_LUT[186][0] = 16;
  m_LUT[187][0] = 2;
  m_LUT[188][0] = 16;
  m_LUT[189][0] = 15;
  m_LUT[190][0] = 4;
  m_LUT[191][0] = 1;
  m_LUT[192][0] = 2;
  m_LUT[193][0] = 6;
  m_LUT[194][0] = 6;
  m_LUT[195][0] = 10;
  m_LUT[196][0] = 5;
  m_LUT[197][0] = 12;
  m_LUT[198][0] = 11;
  m_LUT[199][0] = 16;
  m_LUT[200][0] = 5;
  m_LUT[201][0] = 11;
  m_LUT[202][0] = 12;
  m_LUT[203][0] = 16;
  m_LUT[204][0] = 8;
  m_LUT[205][0] = 5;
  m_LUT[206][0] = 5;
  m_LUT[207][0] = 2;
  m_LUT[208][0] = 5;
  m_LUT[209][0] = 11;
  m_LUT[210][0] = 12;
  m_LUT[211][0] = 16;
  m_LUT[212][0] = 11;
  m_LUT[213][0] = 16;
  m_LUT[214][0] = 16;
  m_LUT[215][0] = 4;
  m_LUT[216][0] = 9;
  m_LUT[217][0] = 5;
  m_LUT[218][0] = 14;
  m_LUT[219][0] = 15;
  m_LUT[220][0] = 5;
  m_LUT[221][0] = 2;
  m_LUT[222][0] = 15;
  m_LUT[223][0] = 1;
  m_LUT[224][0] = 5;
  m_LUT[225][0] = 12;
  m_LUT[226][0] = 11;
  m_LUT[227][0] = 16;
  m_LUT[228][0] = 9;
  m_LUT[229][0] = 14;
  m_LUT[230][0] = 5;
  m_LUT[231][0] = 15;
  m_LUT[232][0] = 11;
  m_LUT[233][0] = 16;
  m_LUT[234][0] = 16;
  m_LUT[235][0] = 4;
  m_LUT[236][0] = 5;
  m_LUT[237][0] = 15;
  m_LUT[238][0] = 2;
  m_LUT[239][0] = 1;
  m_LUT[240][0] = 8;
  m_LUT[241][0] = 5;
  m_LUT[242][0] = 5;
  m_LUT[243][0] = 2;
  m_LUT[244][0] = 5;
  m_LUT[245][0] = 15;
  m_LUT[246][0] = 2;
  m_LUT[247][0] = 1;
  m_LUT[248][0] = 5;
  m_LUT[249][0] = 2;
  m_LUT[250][0] = 15;
  m_LUT[251][0] = 1;
  m_LUT[252][0] = 2;
  m_LUT[253][0] = 1;
  m_LUT[254][0] = 1;
  m_LUT[255][0] = 0;
  m_LUT[0][1] = 0;
  m_LUT[1][1] = 0;
  m_LUT[2][1] = 4;
  m_LUT[3][1] = 0;
  m_LUT[4][1] = 6;
  m_LUT[5][1] = 0;
  m_LUT[6][1] = 34;
  m_LUT[7][1] = 8;
  m_LUT[8][1] = 2;
  m_LUT[9][1] = 32;
  m_LUT[10][1] = 2;
  m_LUT[11][1] = 12;
  m_LUT[12][1] = 2;
  m_LUT[13][1] = 13;
  m_LUT[14][1] = 9;
  m_LUT[15][1] = 8;
  m_LUT[16][1] = 1;
  m_LUT[17][1] = 16;
  m_LUT[18][1] = 11;
  m_LUT[19][1] = 5;
  m_LUT[20][1] = 1;
  m_LUT[21][1] = 16;
  m_LUT[22][1] = 34;
  m_LUT[23][1] = 1;
  m_LUT[24][1] = 16;
  m_LUT[25][1] = 24;
  m_LUT[26][1] = 6;
  m_LUT[27][1] = 1;
  m_LUT[28][1] = 6;
  m_LUT[29][1] = 37;
  m_LUT[30][1] = 9;
  m_LUT[31][1] = 75;
  m_LUT[32][1] = 5;
  m_LUT[33][1] = 9;
  m_LUT[34][1] = 17;
  m_LUT[35][1] = 1;
  m_LUT[36][1] = 17;
  m_LUT[37][1] = 2;
  m_LUT[38][1] = 26;
  m_LUT[39][1] = 5;
  m_LUT[40][1] = 2;
  m_LUT[41][1] = 32;
  m_LUT[42][1] = 17;
  m_LUT[43][1] = 5;
  m_LUT[44][1] = 2;
  m_LUT[45][1] = 13;
  m_LUT[46][1] = 39;
  m_LUT[47][1] = 79;
  m_LUT[48][1] = 1;
  m_LUT[49][1] = 4;
  m_LUT[50][1] = 0;
  m_LUT[51][1] = 0;
  m_LUT[52][1] = 1;
  m_LUT[53][1] = 4;
  m_LUT[54][1] = 16;
  m_LUT[55][1] = 70;
  m_LUT[56][1] = 5;
  m_LUT[57][1] = 17;
  m_LUT[58][1] = 0;
  m_LUT[59][1] = 66;
  m_LUT[60][1] = 25;
  m_LUT[61][1] = 23;
  m_LUT[62][1] = 22;
  m_LUT[63][1] = 67;
  m_LUT[64][1] = 7;
  m_LUT[65][1] = 0;
  m_LUT[66][1] = 19;
  m_LUT[67][1] = 0;
  m_LUT[68][1] = 19;
  m_LUT[69][1] = 19;
  m_LUT[70][1] = 27;
  m_LUT[71][1] = 35;
  m_LUT[72][1] = 8;
  m_LUT[73][1] = 36;
  m_LUT[74][1] = 0;
  m_LUT[75][1] = 12;
  m_LUT[76][1] = 3;
  m_LUT[77][1] = 7;
  m_LUT[78][1] = 7;
  m_LUT[79][1] = 78;
  m_LUT[80][1] = 1;
  m_LUT[81][1] = 20;
  m_LUT[82][1] = 3;
  m_LUT[83][1] = 5;
  m_LUT[84][1] = 23;
  m_LUT[85][1] = 9;
  m_LUT[86][1] = 27;
  m_LUT[87][1] = 7;
  m_LUT[88][1] = 5;
  m_LUT[89][1] = 24;
  m_LUT[90][1] = 1;
  m_LUT[91][1] = 1;
  m_LUT[92][1] = 3;
  m_LUT[93][1] = 1;
  m_LUT[94][1] = 7;
  m_LUT[95][1] = 1;
  m_LUT[96][1] = 35;
  m_LUT[97][1] = 35;
  m_LUT[98][1] = 30;
  m_LUT[99][1] = 20;
  m_LUT[100][1] = 31;
  m_LUT[101][1] = 31;
  m_LUT[102][1] = 26;
  m_LUT[103][1] = 93;
  m_LUT[104][1] = 39;
  m_LUT[105][1] = 0;
  m_LUT[106][1] = 30;
  m_LUT[107][1] = 14;
  m_LUT[108][1] = 22;
  m_LUT[109][1] = 15;
  m_LUT[110][1] = 92;
  m_LUT[111][1] = 97;
  m_LUT[112][1] = 10;
  m_LUT[113][1] = 0;
  m_LUT[114][1] = 4;
  m_LUT[115][1] = 71;
  m_LUT[116][1] = 34;
  m_LUT[117][1] = 6;
  m_LUT[118][1] = 89;
  m_LUT[119][1] = 82;
  m_LUT[120][1] = 10;
  m_LUT[121][1] = 8;
  m_LUT[122][1] = 4;
  m_LUT[123][1] = 8;
  m_LUT[124][1] = 16;
  m_LUT[125][1] = 67;
  m_LUT[126][1] = 16;
  m_LUT[127][1] = 67;
  m_LUT[128][1] = 3;
  m_LUT[129][1] = 18;
  m_LUT[130][1] = 3;
  m_LUT[131][1] = 4;
  m_LUT[132][1] = 10;
  m_LUT[133][1] = 4;
  m_LUT[134][1] = 38;
  m_LUT[135][1] = 8;
  m_LUT[136][1] = 18;
  m_LUT[137][1] = 25;
  m_LUT[138][1] = 18;
  m_LUT[139][1] = 33;
  m_LUT[140][1] = 7;
  m_LUT[141][1] = 3;
  m_LUT[142][1] = 3;
  m_LUT[143][1] = 74;
  m_LUT[144][1] = 33;
  m_LUT[145][1] = 28;
  m_LUT[146][1] = 33;
  m_LUT[147][1] = 21;
  m_LUT[148][1] = 37;
  m_LUT[149][1] = 28;
  m_LUT[150][1] = 1;
  m_LUT[151][1] = 10;
  m_LUT[152][1] = 29;
  m_LUT[153][1] = 24;
  m_LUT[154][1] = 29;
  m_LUT[155][1] = 95;
  m_LUT[156][1] = 23;
  m_LUT[157][1] = 94;
  m_LUT[158][1] = 11;
  m_LUT[159][1] = 99;
  m_LUT[160][1] = 3;
  m_LUT[161][1] = 7;
  m_LUT[162][1] = 21;
  m_LUT[163][1] = 1;
  m_LUT[164][1] = 1;
  m_LUT[165][1] = 0;
  m_LUT[166][1] = 26;
  m_LUT[167][1] = 5;
  m_LUT[168][1] = 22;
  m_LUT[169][1] = 25;
  m_LUT[170][1] = 8;
  m_LUT[171][1] = 3;
  m_LUT[172][1] = 7;
  m_LUT[173][1] = 3;
  m_LUT[174][1] = 5;
  m_LUT[175][1] = 3;
  m_LUT[176][1] = 14;
  m_LUT[177][1] = 0;
  m_LUT[178][1] = 4;
  m_LUT[179][1] = 67;
  m_LUT[180][1] = 14;
  m_LUT[181][1] = 0;
  m_LUT[182][1] = 12;
  m_LUT[183][1] = 10;
  m_LUT[184][1] = 32;
  m_LUT[185][1] = 91;
  m_LUT[186][1] = 2;
  m_LUT[187][1] = 83;
  m_LUT[188][1] = 17;
  m_LUT[189][1] = 17;
  m_LUT[190][1] = 64;
  m_LUT[191][1] = 71;
  m_LUT[192][1] = 3;
  m_LUT[193][1] = 7;
  m_LUT[194][1] = 3;
  m_LUT[195][1] = 24;
  m_LUT[196][1] = 2;
  m_LUT[197][1] = 2;
  m_LUT[198][1] = 18;
  m_LUT[199][1] = 20;
  m_LUT[200][1] = 6;
  m_LUT[201][1] = 19;
  m_LUT[202][1] = 6;
  m_LUT[203][1] = 21;
  m_LUT[204][1] = 2;
  m_LUT[205][1] = 64;
  m_LUT[206][1] = 68;
  m_LUT[207][1] = 65;
  m_LUT[208][1] = 15;
  m_LUT[209][1] = 36;
  m_LUT[210][1] = 15;
  m_LUT[211][1] = 19;
  m_LUT[212][1] = 6;
  m_LUT[213][1] = 0;
  m_LUT[214][1] = 13;
  m_LUT[215][1] = 66;
  m_LUT[216][1] = 2;
  m_LUT[217][1] = 90;
  m_LUT[218][1] = 2;
  m_LUT[219][1] = 19;
  m_LUT[220][1] = 65;
  m_LUT[221][1] = 81;
  m_LUT[222][1] = 11;
  m_LUT[223][1] = 69;
  m_LUT[224][1] = 11;
  m_LUT[225][1] = 11;
  m_LUT[226][1] = 38;
  m_LUT[227][1] = 18;
  m_LUT[228][1] = 6;
  m_LUT[229][1] = 6;
  m_LUT[230][1] = 88;
  m_LUT[231][1] = 18;
  m_LUT[232][1] = 2;
  m_LUT[233][1] = 9;
  m_LUT[234][1] = 4;
  m_LUT[235][1] = 65;
  m_LUT[236][1] = 69;
  m_LUT[237][1] = 9;
  m_LUT[238][1] = 80;
  m_LUT[239][1] = 65;
  m_LUT[240][1] = 10;
  m_LUT[241][1] = 73;
  m_LUT[242][1] = 77;
  m_LUT[243][1] = 66;
  m_LUT[244][1] = 76;
  m_LUT[245][1] = 0;
  m_LUT[246][1] = 96;
  m_LUT[247][1] = 66;
  m_LUT[248][1] = 72;
  m_LUT[249][1] = 98;
  m_LUT[250][1] = 2;
  m_LUT[251][1] = 70;
  m_LUT[252][1] = 64;
  m_LUT[253][1] = 68;
  m_LUT[254][1] = 64;
  m_LUT[255][1] = 0;
  
  m_LocationOffset[1][0] = 0.5;
  m_LocationOffset[2][0] = 1;
  m_LocationOffset[3][0] = 0.5;
  m_LocationOffset[4][0] = 0;
  m_LocationOffset[5][0] = 0.5;
  m_LocationOffset[6][0] = 1;
  m_LocationOffset[7][0] = 0.5;
  m_LocationOffset[8][0] = 0;
  m_LocationOffset[9][0] = 0;
  m_LocationOffset[10][0] = 1;
  m_LocationOffset[11][0] = 1;
  m_LocationOffset[12][0] = 0;
  m_LocationOffset[13][0] = 0.5;   
  m_LocationOffset[1][1] = 0;
  m_LocationOffset[2][1] = 0.5;
  m_LocationOffset[3][1] = 1;
  m_LocationOffset[4][1] = 0.5;
  m_LocationOffset[5][1] = 0;
  m_LocationOffset[6][1] = 0.5;
  m_LocationOffset[7][1] = 1;
  m_LocationOffset[8][1] = 0.5;
  m_LocationOffset[9][1] = 0;
  m_LocationOffset[10][1] = 0;
  m_LocationOffset[11][1] = 1;
  m_LocationOffset[12][1] = 1;
  m_LocationOffset[13][1] = 0.5;  
  m_LocationOffset[1][2] = 0;
  m_LocationOffset[2][2] = 0;
  m_LocationOffset[3][2] = 0;
  m_LocationOffset[4][2] = 0;
  m_LocationOffset[5][2] = 1;
  m_LocationOffset[6][2] = 1;
  m_LocationOffset[7][2] = 1;
  m_LocationOffset[8][2] = 1;
  m_LocationOffset[9][2] = 0.5;
  m_LocationOffset[10][2] = 0.5;
  m_LocationOffset[11][2] = 0.5;
  m_LocationOffset[12][2] = 0.5;
  m_LocationOffset[13][2] = 0.5;  

}

template<class TOutputMesh>
void
BinaryMask3DMeshSource<TOutputMesh>
::CreateMesh()
{
  BinaryImageIterator it1( m_BinaryImage, m_BinaryImage->GetBufferedRegion() );
  BinaryImageIterator it2( m_BinaryImage, m_BinaryImage->GetBufferedRegion() );
  BinaryImageIterator it3( m_BinaryImage, m_BinaryImage->GetBufferedRegion() );
  BinaryImageIterator it4( m_BinaryImage, m_BinaryImage->GetBufferedRegion() );

  it1.GoToBegin();
  it2.GoToBegin();
  it3.GoToBegin();
  it4.GoToBegin();

  BinaryImageSizeType binaryImageSize = m_BinaryImage->GetBufferedRegion().GetSize();
  m_ImageWidth  = binaryImageSize[0];
  m_ImageHeight = binaryImageSize[1];
  m_ImageDepth  = binaryImageSize[2];
  int frame = m_ImageWidth * m_ImageHeight;
  int row = m_ImageWidth;

  int i = 0, j, k;

  while ( i < frame ) {
    ++it3;
    ++it4;
    i++;
  }

  i = 0;

  while ( i < row ) {
    ++it2;
    ++it4;
    i++;
  }

  unsigned char vertexindex;

  m_CurrentRow = ( unsigned long ** ) malloc( 200*sizeof(unsigned long *) );  
  for ( i=0; i<200; i++ ) m_CurrentRow[i] = ( unsigned long * ) malloc( 2*sizeof( unsigned long ) );
  m_CurrentFrame = ( unsigned long ** ) malloc( 2000*sizeof(unsigned short *) );  
  for ( i=0; i<2000; i++ ) m_CurrentFrame[i] = ( unsigned long * ) malloc( 2*sizeof( unsigned long ) );
//  m_LastRow = ( unsigned long ** ) malloc( 200*sizeof(unsigned long *) );  
//  for ( i=0; i<200; i++ ) m_LastRow[i] = ( unsigned long * ) malloc( 2*sizeof( unsigned long ) );
//  m_LastFrame = ( unsigned long ** ) malloc( 2000*sizeof(unsigned long *) );  
//  for ( i=0; i<2000; i++ ) m_LastFrame[i] = ( unsigned long * ) malloc( 2*sizeof( unsigned long ) );

  i = 0;
  while ( !it4.IsAtEnd() ) {
    vertexindex = 0;
    
    if ( it1.Value() == m_ObjectValue ) vertexindex += 1;  
    if ( it2.Value() == m_ObjectValue ) vertexindex += 8;  
    if ( it3.Value() == m_ObjectValue ) vertexindex += 16;  
    if ( it4.Value() == m_ObjectValue ) vertexindex += 128;
    ++it1;
    ++it2;
    ++it3;
    ++it4;


    if (( i % m_ImageWidth < m_ImageWidth - 1 ) && ((i % (m_ImageWidth*m_ImageHeight)) / m_ImageWidth < m_ImageHeight - 1) ) {
      if ( it1.Value() == m_ObjectValue ) vertexindex += 2;  
      if ( it2.Value() == m_ObjectValue ) vertexindex += 4;  
      if ( it3.Value() == m_ObjectValue ) vertexindex += 32;  
      if ( it4.Value() == m_ObjectValue ) vertexindex += 64;
    } else {
      if ((i % (m_ImageWidth*m_ImageHeight)) / m_ImageWidth == m_ImageHeight - 1) {
        if ( vertexindex > 50 ) vertexindex -= 128;
        if ( ((vertexindex > 7) && (vertexindex < 10)) || (vertexindex > 17) ) vertexindex -= 8;
        if ( it1.Value() == m_ObjectValue ) vertexindex += 2; 
        if ( it3.Value() == m_ObjectValue ) vertexindex += 32;  
      }
    }

    for ( j=0; j<14; j++ ) m_CurrentVoxel[j] = 0;
   
    if ( ( vertexindex == 0 ) || (vertexindex == 255 ) ) {
//      for ( j=0; j<13; j++ ) m_LastVoxel[j] = 0;
    } else {
      this->AddCells( m_LUT[vertexindex][0], m_LUT[vertexindex][1], i );
    }
    i++;    
  }
  
}

template<class TOutputMesh>
void
BinaryMask3DMeshSource<TOutputMesh>
::AddCells( unsigned char celltype, unsigned char celltran, int index )
{
  unsigned char activenodes[14];
  int i;  

//  if (m_NumberOfCells > 1365)
//    std::cout << "stop" << std::endl;

  if ( (index % m_ImageWidth == 0) || (index > m_LastVoxelIndex + 1) ) {
    m_ColFlag = 0; 
    for (i=0; i<14; i++) m_LastVoxel[i] = 0;
  }
  else m_ColFlag = 1;
   
  if ( ((index % (m_ImageWidth*m_ImageHeight)) < m_ImageWidth) || ((index / m_ImageWidth) > m_LastRowIndex + 1) ) m_RowFlag = 0; else m_RowFlag = 1;

  if ( (index < m_ImageWidth*m_ImageHeight) || ((index / (m_ImageWidth*m_ImageHeight)) > m_LastFrameIndex + 1) ) m_FrameFlag = 0; else m_FrameFlag = 1;

  /** allocate memory */
  if ( m_RowFlag == 1 ) {
    if ( (index / m_ImageHeight) != m_LastRowIndex ) {
      if ( m_LastRowNum == 0 ) m_LastRow = ( unsigned long ** ) malloc( m_CurrentRowIndex*sizeof(unsigned long *) );
      else m_LastRow = ( unsigned long ** ) realloc( m_LastRow, m_CurrentRowIndex*sizeof(unsigned long *) );  
      for ( i=0; i<m_CurrentRowIndex; i++ ) {
        if ( i > m_LastRowNum-1 ) m_LastRow[i] = ( unsigned long * ) malloc( 2*sizeof( unsigned long ) );
        m_LastRow[i][0] = m_CurrentRow[i][0];
        m_LastRow[i][1] = m_CurrentRow[i][1];
      } 
      m_LastRowNum = m_CurrentRowIndex;
      m_CurrentRowIndex = 0;
    }
  } else {
    if ( m_ColFlag == 0 ) {
      if ( m_LastRowNum > 0 ) {
        for ( i=0; i<m_LastRowNum; i++ ) free (m_LastRow[i]);
        free (m_LastRow);
      }
      m_LastRowNum = 0;
    }
  } 
  
  if ( m_FrameFlag == 1 ) {
    if ( (index / (m_ImageWidth * m_ImageHeight)) != m_LastFrameIndex ) {
      if ( m_LastFrameNum == 0 ) m_LastFrame = ( unsigned long ** ) malloc( m_CurrentFrameIndex*sizeof(unsigned long *) );
      else m_LastFrame = ( unsigned long ** ) realloc( m_LastFrame, m_CurrentFrameIndex*sizeof(unsigned long *) );
      for ( i=0; i<m_CurrentFrameIndex; i++ ) {
        if ( i > m_LastFrameNum-1 ) m_LastFrame[i] = ( unsigned long * ) malloc( 2*sizeof( unsigned long ) ); 
        m_LastFrame[i][0] = m_CurrentFrame[i][0];
        m_LastFrame[i][1] = m_CurrentFrame[i][1];  
      }
      m_LastFrameNum = m_CurrentFrameIndex;
      m_CurrentFrameIndex = 0;
    }
  } else {
    if ( index % (m_ImageWidth * m_ImageHeight) == 0 ) {
      for ( i=0; i<m_LastFrameNum; i++ ) 
          free (m_LastFrame[i]);
      free (m_LastFrame);
    }
  } 

  m_LastVoxelIndex = index;
  m_LastRowIndex = index / m_ImageWidth;  
  m_LastFrameIndex = index / (m_ImageWidth*m_ImageHeight);
    
  m_AvailableNodes[1] = 0;
  m_AvailableNodes[2] = 0;
  m_AvailableNodes[3] = 0;
  m_AvailableNodes[4] = 0;
  m_AvailableNodes[5] = 0;
  m_AvailableNodes[6] = 1;
  m_AvailableNodes[7] = 1;
  m_AvailableNodes[8] = 0;
  m_AvailableNodes[9] = 0;
  m_AvailableNodes[10] = 0;
  m_AvailableNodes[11] = 1;
  m_AvailableNodes[12] = 0;
  m_AvailableNodes[13] = 1;
  
  if ( m_ColFlag == 0 ) {
    m_AvailableNodes[4] = 1;
    m_AvailableNodes[8] = 1;
    m_AvailableNodes[9] = 1;
    m_AvailableNodes[12] = 1;
  } 
  
  if ( m_RowFlag == 0 ) {
    m_AvailableNodes[1] = 1;
    m_AvailableNodes[5] = 1;
    m_AvailableNodes[9] = 1;
    m_AvailableNodes[10] = 1;
  } 

  
  if ( m_FrameFlag == 0 ) {
    m_AvailableNodes[1] = 1;
    m_AvailableNodes[2] = 1;
    m_AvailableNodes[3] = 1;
    m_AvailableNodes[4] = 1;
  } 

  TriCell::Pointer insertCell;
  unsigned long tripoints[3];
  unsigned char *tp;
  tp = (unsigned char *) malloc( 3*sizeof( unsigned char ) );

  unsigned long *tpl;
  tpl = (unsigned long *) malloc( 3*sizeof( unsigned long ) );

  switch ( (int) celltype ) {
  case 1:
    tp[0] = 1;
    tp[1] = 9;
    tp[2] = 4;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    break;
  case 2:
    tp[0] = 4;
    tp[1] = 2;
    tp[2] = 9;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 10;
    tp[1] = 9;
    tp[2] = 2;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    break;
  case 3:
    tp[0] = 1;
    tp[1] = 9;
    tp[2] = 4;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 2;
    tp[1] = 3;
    tp[2] = 11;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    break;
  case 4:
    tp[0] = 1;
    tp[1] = 9;
    tp[2] = 4;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 6;
    tp[1] = 11;
    tp[2] = 7;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    break;
  case 5:
    tp[0] = 1;
    tp[1] = 2;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 1;
    tp[1] = 13;
    tp[2] = 9;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 9;
    tp[1] = 13;
    tp[2] = 8;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 13;
    tp[1] = 2;
    tp[2] = 6;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 13;
    tp[1] = 6;
    tp[2] = 8;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    break;
  case 6:
    tp[0] = 10;
    tp[1] = 9;
    tp[2] = 2;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 4;
    tp[1] = 2;
    tp[2] = 9;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 6;
    tp[1] = 11;
    tp[2] = 7;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    break;
  case 7:
    tp[0] = 1;
    tp[1] = 2;
    tp[2] = 10;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 6;
    tp[1] = 11;
    tp[2] = 7;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 3;
    tp[1] = 4;
    tp[2] = 12;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    break;
  case 8:
    tp[0] = 13;
    tp[1] = 2;
    tp[2] = 6;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 13;
    tp[1] = 6;
    tp[2] = 8;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 13;
    tp[1] = 8;
    tp[2] = 4;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 13;
    tp[1] = 4;
    tp[2] = 2;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    break;
  case 9:
    tp[0] = 1;
    tp[1] = 10;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 10;
    tp[1] = 6;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 6;
    tp[1] = 7;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 7;
    tp[1] = 12;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 12;
    tp[1] = 4;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 1;
    tp[1] = 13;
    tp[2] = 4;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    break;
  case 10:
    tp[0] = 1;
    tp[1] = 9;
    tp[2] = 3;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 9;
    tp[1] = 12;
    tp[2] = 3;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 5;
    tp[1] = 10;
    tp[2] = 7;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 10;
    tp[1] = 11;
    tp[2] = 7;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    break;
  case 11:
    tp[0] = 1;
    tp[1] = 10;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 13;
    tp[1] = 10;
    tp[2] = 11;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 7;
    tp[1] = 13;
    tp[2] = 11;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 7;
    tp[1] = 8;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 13;
    tp[1] = 8;
    tp[2] = 4;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 1;
    tp[1] = 13;
    tp[2] = 4;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    break;
  case 12:
    tp[0] = 1;
    tp[1] = 2;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 1;
    tp[1] = 13;
    tp[2] = 9;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 9;
    tp[1] = 13;
    tp[2] = 8;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 13;
    tp[1] = 2;
    tp[2] = 6;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 13;
    tp[1] = 6;
    tp[2] = 8;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 3;
    tp[1] = 4;
    tp[2] = 12;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    break;
  case 13:
    tp[0] = 1;
    tp[1] = 9;
    tp[2] = 4;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 5;
    tp[1] = 10;
    tp[2] = 6;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 2;
    tp[1] = 3;
    tp[2] = 11;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 8;
    tp[1] = 7;
    tp[2] = 12;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    break;
  case 14:
    tp[0] = 1;
    tp[1] = 10;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 10;
    tp[1] = 6;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 6;
    tp[1] = 7;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 7;
    tp[1] = 12;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 12;
    tp[1] = 4;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 1;
    tp[1] = 13;
    tp[2] = 4;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 2;
    tp[1] = 3;
    tp[2] = 11;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    break;
  case 15:
    tp[0] = 1;
    tp[1] = 10;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 2;
    tp[1] = 13;
    tp[2] = 10;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 2;
    tp[1] = 3;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 3;
    tp[1] = 12;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 4;
    tp[1] = 13;
    tp[2] = 12;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 1;
    tp[1] = 13;
    tp[2] = 4;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    break;
  case 16:
    tp[0] = 13;
    tp[1] = 1;
    tp[2] = 5;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 5;
    tp[1] = 6;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 13;
    tp[1] = 6;
    tp[2] = 2;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 2;
    tp[1] = 3;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 3;
    tp[1] = 12;
    tp[2] = 13;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 4;
    tp[1] = 13;
    tp[2] = 12;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    tp[0] = 1;
    tp[1] = 13;
    tp[2] = 4;
    CellTransfer( tp, celltran ); 
    AddNodes(index, tp, tpl);
    tripoints[0] = tpl[0];
    tripoints[1] = tpl[2];
    tripoints[2] = tpl[1];
    insertCell = TriCell::New();
    insertCell->SetPointIds(tripoints);
    this->GetOutput()->SetCell(m_NumberOfCells, insertCell);
    this->GetOutput()->SetCellData(m_NumberOfCells, 0.0);
    m_NumberOfCells++;
    break; 
  }

  m_LastVoxel[4] = m_CurrentVoxel[2]; 
  m_LastVoxel[9] = m_CurrentVoxel[10];
  m_LastVoxel[8] = m_CurrentVoxel[6];
  m_LastVoxel[12] = m_CurrentVoxel[11];
  for ( i=1; i<14; i++ ) m_CurrentVoxel[i] = 0;
}

template<class TOutputMesh>
void
BinaryMask3DMeshSource<TOutputMesh>
::AddNodes( int index, unsigned char *nodesid, unsigned long *globalnodesid )
{
  int i = 0, j;
  OPointType new_p;
  unsigned long currentrowtmp[4][2] = {{0,0},{0,0},{0,0},{0,0}};
  unsigned long currentframetmp[4][2] = {{0,0},{0,0},{0,0},{0,0}};

  unsigned char test[3];

  for ( i=0; i<3; i++ ) {
    m_PointFound = 0;
   test[i] = 0;

    if ( m_AvailableNodes[nodesid[i]] != 0 ) {
      m_PointFound = 1;
      test[i] = 1;

      new_p[0] = m_LocationOffset[nodesid[i]][0] + ( index % m_ImageWidth ) + 0.5;
      new_p[1] = m_LocationOffset[nodesid[i]][1] + ( (index % (m_ImageWidth*m_ImageHeight)) / m_ImageHeight ) + 0.5;
      new_p[2] = m_LocationOffset[nodesid[i]][2] + ( index / (m_ImageWidth*m_ImageHeight) ) + 0.5;
      this->GetOutput()->SetPoint( m_NumberOfNodes, new_p );

      switch ( nodesid[i] ) {
      case 2:
        m_CurrentVoxel[2] = m_NumberOfNodes;
        break;
      case 6:
        m_CurrentVoxel[6] = m_NumberOfNodes;
        currentframetmp[1][1] = m_NumberOfNodes;
        currentframetmp[1][0] = (index%(m_ImageWidth*m_ImageHeight))*13+2;
//        m_CurrentFrame[m_CurrentFrameIndex][0] = (index%(m_ImageWidth*m_ImageHeight))*13+2;  
//        m_CurrentFrame[m_CurrentFrameIndex++][1] = m_NumberOfNodes;
        break;
      case 10:
        m_CurrentVoxel[10] = m_NumberOfNodes;
        break;
      case 11:
        m_CurrentVoxel[11] = m_NumberOfNodes;
        currentrowtmp[3][1] = m_NumberOfNodes;
        currentrowtmp[3][0] = (index%m_ImageWidth)*13+10;
//        m_CurrentRow[m_CurrentRowIndex][1] = m_NumberOfNodes;
//        m_CurrentRow[m_CurrentRowIndex++][0] = (index%m_ImageWidth)*13+10;
        break;
      case 3:
        currentrowtmp[0][1] = m_NumberOfNodes;
        currentrowtmp[0][0] = (index%m_ImageWidth)*13+1;
//        m_CurrentRow[m_CurrentRowIndex][1] = m_NumberOfNodes;
//        m_CurrentRow[m_CurrentRowIndex++][0] = (index%m_ImageWidth)*13+1;
        break;
      case 7:
        currentrowtmp[1][1] = m_NumberOfNodes;
        currentrowtmp[1][0] = (index%m_ImageWidth)*13+5;
        currentframetmp[2][1] = m_NumberOfNodes;
        currentframetmp[2][0] = (index%(m_ImageWidth*m_ImageHeight))*13+3;
//        m_CurrentRow[m_CurrentRowIndex][0] = (index%m_ImageWidth)*13+5;
//        m_CurrentRow[m_CurrentRowIndex++][1] = m_NumberOfNodes;
//        m_CurrentFrame[m_CurrentFrameIndex][0] = (index%(m_ImageWidth*m_ImageHeight))*13+3;
//        m_CurrentFrame[m_CurrentFrameIndex++][1] = m_NumberOfNodes;
        break;
      case 12:
        currentrowtmp[2][1] = m_NumberOfNodes;
        currentrowtmp[2][0] = (index%m_ImageWidth)*13+9;
//        m_CurrentRow[m_CurrentRowIndex][0] = (index%m_ImageWidth)*13+9;
//        m_CurrentRow[m_CurrentRowIndex++][1] = m_NumberOfNodes;
        break;
      case 5:
        currentframetmp[0][1] = m_NumberOfNodes;
        currentframetmp[0][0] = (index%(m_ImageWidth*m_ImageHeight))*13+1;
//        m_CurrentFrame[m_CurrentFrameIndex][0] = (index%(m_ImageWidth*m_ImageHeight))*13+1;
//        m_CurrentFrame[m_CurrentFrameIndex++][1] = m_NumberOfNodes;
        break;
      case 8:
        currentframetmp[3][1] = m_NumberOfNodes;
        currentframetmp[3][0] = (index%(m_ImageWidth*m_ImageHeight))*13+4;
//        m_CurrentFrame[m_CurrentFrameIndex][0] = (index%(m_ImageWidth*m_ImageHeight))*13+4;
//        m_CurrentFrame[m_CurrentFrameIndex++][1] = m_NumberOfNodes;
        break;
      case 1:
        m_CurrentVoxel[1] = m_NumberOfNodes;
        break;
      case 4:
        m_CurrentVoxel[4] = m_NumberOfNodes;
        break;
      case 9:
        m_CurrentVoxel[9] = m_NumberOfNodes;
        break;
      case 13:
        m_CurrentVoxel[13] = m_NumberOfNodes;
        break;
      }

//      if ( (m_CurrentRowIndex > 1) && (m_CurrentRow[m_CurrentRowIndex][0] < m_CurrentRow[m_CurrentRowIndex-1][0]) )
//      std::cout << "disorder" << std::endl;
/*
      if ( m_CurrentRowIndex == m_CurrentRowNum ) {
        m_CurrentRowNum += 100;
        m_CurrentRow = (unsigned long **) realloc(m_CurrentRow, sizeof(unsigned long *) * m_CurrentRowNum);
        for ( j = m_CurrentRowIndex; j < m_CurrentRowNum; j++ ) m_CurrentRow[j] = (unsigned long *) malloc(sizeof(unsigned long) * 2);
      }

      if ( m_CurrentFrameIndex == m_CurrentFrameNum ) {
        m_CurrentFrameNum += 1000;
        m_CurrentFrame = (unsigned long **) realloc(m_CurrentFrame, sizeof(unsigned long *) * m_CurrentFrameNum);
        for ( j = m_CurrentFrameIndex; j < m_CurrentFrameNum; j++ ) m_CurrentFrame[j] = (unsigned long *) malloc(sizeof(unsigned long) * 2);
      }
*/
      globalnodesid[i] = m_NumberOfNodes;
      m_AvailableNodes[ nodesid[i] ] = 0;
      m_CurrentVoxel[ nodesid[i] ] = m_NumberOfNodes;
      m_NumberOfNodes++;
/*
      if ( m_NumberOfNodes == m_NodeLimit ) {
        m_NodeLimit += 1000;
        this->GetOutput()->GetPoints()->Reserve(m_NodeLimit);
      } 
*/
    } else {
      if ( m_CurrentVoxel[ nodesid[i] ] != 0 ) {
        globalnodesid[i] = m_CurrentVoxel[ nodesid[i] ];
        m_PointFound = 1;
        test[i] = 2;

        continue;
      }
      if ( m_LastVoxel[ nodesid[i] ] != 0 ) {
        globalnodesid[i] = m_LastVoxel[ nodesid[i] ];
        m_PointFound = 1;
        test[i] = 3;

        continue;
      }
      if ( (m_LastRowNum != 0) && ( (nodesid[i] == 1) || (nodesid[i] == 5) || (nodesid[i] == 9) || (nodesid[i] == 10) ) ) {
        test[i] = 4;
        globalnodesid[i] = this->SearchThroughLastRow((index % m_ImageWidth)*13+nodesid[i], 0, m_LastRowNum-1);
        if ( m_PointFound != 0 ) continue;
        else {
          if (nodesid[i] == 9) globalnodesid[i] = this->SearchThroughLastRow((index % m_ImageWidth)*13-3, 0, m_LastRowNum-1);
          if ( m_PointFound != 0 ) continue;
        }
      }
      if ( (m_LastFrameNum != 0) && ( (nodesid[i] == 1) || (nodesid[i] == 2) || (nodesid[i] == 3) || (nodesid[i] == 4) ) ) {
        test[i] = 5;
        globalnodesid[i] = this->SearchThroughLastFrame((index % (m_ImageWidth*m_ImageHeight))*13+nodesid[i], 0, m_LastFrameNum-1);
        if ( m_PointFound != 0 ) continue;
        else {
          if (nodesid[i] == 4) globalnodesid[i] = this->SearchThroughLastFrame((index % (m_ImageWidth*m_ImageHeight))*13-11, 0, m_LastFrameNum-1);
          if (nodesid[i] == 1) globalnodesid[i] = this->SearchThroughLastFrame((index % (m_ImageWidth*m_ImageHeight) - m_ImageWidth)*13+3, 0, m_LastFrameNum-1);
          if ( m_PointFound != 0 ) continue;
        }
      }
    }

    if (m_PointFound == 0) {
      m_AvailableNodes[nodesid[i]] = 1;
      i--;
    }
  }

//  if ((globalnodesid[0] > 10000) || (globalnodesid[1] > 10000) || (globalnodesid[2] > 10000))
//    std::cout << " abnormal " << std::endl;

  i = 0;
  while (i < 4) {
    if ( currentrowtmp[i][0] != 0 ) {
      m_CurrentRow[m_CurrentRowIndex][1] = currentrowtmp[i][1];
      m_CurrentRow[m_CurrentRowIndex++][0] = currentrowtmp[i][0]; 
      if ( m_CurrentRowIndex == m_CurrentRowNum ) {
        m_CurrentRowNum += 100;
        m_CurrentRow = (unsigned long **) realloc(m_CurrentRow, sizeof(unsigned long *) * m_CurrentRowNum);
        for ( j = m_CurrentRowIndex; j < m_CurrentRowNum; j++ ) m_CurrentRow[j] = (unsigned long *) malloc(sizeof(unsigned long) * 2);
      }
    }

//    if ( (m_CurrentRowIndex > 2) && (m_CurrentRow[m_CurrentRowIndex-1][0] < m_CurrentRow[m_CurrentRowIndex-2][0]) )
//      std::cout << "disorder" << std::endl;

    if ( currentframetmp[i][0] != 0 ) {
      m_CurrentFrame[m_CurrentFrameIndex][1] = currentframetmp[i][1];
      m_CurrentFrame[m_CurrentFrameIndex++][0] = currentframetmp[i][0]; 
      if ( m_CurrentFrameIndex == m_CurrentFrameNum ) {
        m_CurrentFrameNum += 1000;
        m_CurrentFrame = (unsigned long **) realloc(m_CurrentFrame, sizeof(unsigned long *) * m_CurrentFrameNum);
        for ( j = m_CurrentFrameIndex; j < m_CurrentFrameNum; j++ ) m_CurrentFrame[j] = (unsigned long *) malloc(sizeof(unsigned long) * 2);
      }
    }

    i++;
  }
}

template<class TOutputMesh>
void
BinaryMask3DMeshSource<TOutputMesh>
::CellTransfer( unsigned char *nodesid, unsigned char celltran )
{
  if ( (celltran & 1) != 0 ) {
    this->ZFlip(nodesid);
    if ( celltran > 64 ) celltran -= 64;
    else celltran += 64;
  }
  if ( (celltran & 2) != 0 ) {
    this->YFlip(nodesid);
    if ( celltran > 64 ) celltran -= 64;
    else celltran += 64;
  }
  if ( (celltran & 4) != 0 ) {
    this->XFlip(nodesid);
    if ( celltran > 64 ) celltran -= 64;
    else celltran += 64;
  }
  if ( (celltran & 8) != 0 ) this->ZRotation(nodesid);
  if ( (celltran & 16) != 0 ) this->YRotation(nodesid);
  if ( (celltran & 32) != 0 ) this->XRotation(nodesid);
  if ( (celltran & 64) != 0 ) this->inverse(nodesid);
}

template<class TOutputMesh>
unsigned long
BinaryMask3DMeshSource<TOutputMesh>
::SearchThroughLastRow( int index, int start, int end )
{
  int mid;
  if ( (end - start) > 1 ) {
    mid = floor(static_cast<float>((start + end)/2));
    if ( index == m_LastRow[mid][0] ) {
      m_PointFound = 1;
      return m_LastRow[mid][1];
    }
    else {
      if ( index > m_LastRow[mid][0] ) return this->SearchThroughLastRow(index, mid+1, end);
      else return this->SearchThroughLastRow(index, start, mid);
    }
  } else {
    if ( index == m_LastRow[start][0] ) {
      m_PointFound = 1;
      return m_LastRow[start][1];
    }
    if ( index == m_LastRow[end][0] ) {
      m_PointFound = 1;  
      return m_LastRow[end][1];
    }
  } 
  return 0;
}

template<class TOutputMesh>
unsigned long
BinaryMask3DMeshSource<TOutputMesh>
::SearchThroughLastFrame( int index, int start, int end )
{
  int mid;
  if ( (end - start) > 1 ) {
    mid = floor(static_cast<float>((start + end)/2));
    if ( index == m_LastFrame[mid][0] ) {
      m_PointFound = 1;
      return m_LastFrame[mid][1];
    }
    else {
      if ( index > m_LastFrame[mid][0] ) return this->SearchThroughLastFrame(index, mid+1, end);
      else return this->SearchThroughLastFrame(index, start, mid);
    }
  } else {
    if ( index == m_LastFrame[start][0] ) {
      m_PointFound = 1;
      return m_LastFrame[start][1];
    }
    if ( index == m_LastFrame[end][0] ) {
      m_PointFound = 1;      
      return m_LastFrame[end][1];
    }
  } 
}

template<class TOutputMesh>
void
BinaryMask3DMeshSource<TOutputMesh>
::PrintSelf( std::ostream& os, Indent indent ) const
{
  Superclass::PrintSelf(os, indent);

  os << indent << "BinaryMask3DMeshSource" << std::endl;
}

} /** end namespace itk. */

#endif
