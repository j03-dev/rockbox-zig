// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.31.0
// 	protoc        (unknown)
// source: rockbox/search/v1alpha1/track.proto

package v1alpha1

import (
	protoreflect "google.golang.org/protobuf/reflect/protoreflect"
	protoimpl "google.golang.org/protobuf/runtime/protoimpl"
	reflect "reflect"
	sync "sync"
)

const (
	// Verify that this generated code is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(20 - protoimpl.MinVersion)
	// Verify that runtime/protoimpl is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(protoimpl.MaxVersion - 20)
)

type Track struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Id          string  `protobuf:"bytes,1,opt,name=id,proto3" json:"id,omitempty"`
	Path        string  `protobuf:"bytes,2,opt,name=path,proto3" json:"path,omitempty"`
	Title       string  `protobuf:"bytes,3,opt,name=title,proto3" json:"title,omitempty"`
	Artist      string  `protobuf:"bytes,4,opt,name=artist,proto3" json:"artist,omitempty"`
	Album       string  `protobuf:"bytes,5,opt,name=album,proto3" json:"album,omitempty"`
	AlbumArtist string  `protobuf:"bytes,6,opt,name=album_artist,json=albumArtist,proto3" json:"album_artist,omitempty"`
	Bitrate     uint32  `protobuf:"varint,7,opt,name=bitrate,proto3" json:"bitrate,omitempty"`
	Composer    string  `protobuf:"bytes,8,opt,name=composer,proto3" json:"composer,omitempty"`
	DiscNumber  uint32  `protobuf:"varint,9,opt,name=disc_number,json=discNumber,proto3" json:"disc_number,omitempty"`
	Filesize    uint32  `protobuf:"varint,10,opt,name=filesize,proto3" json:"filesize,omitempty"`
	Frequency   uint32  `protobuf:"varint,11,opt,name=frequency,proto3" json:"frequency,omitempty"`
	Length      uint32  `protobuf:"varint,12,opt,name=length,proto3" json:"length,omitempty"`
	TrackNumber uint32  `protobuf:"varint,13,opt,name=track_number,json=trackNumber,proto3" json:"track_number,omitempty"`
	Year        uint32  `protobuf:"varint,14,opt,name=year,proto3" json:"year,omitempty"`
	YearString  string  `protobuf:"bytes,15,opt,name=year_string,json=yearString,proto3" json:"year_string,omitempty"`
	Genre       string  `protobuf:"bytes,16,opt,name=genre,proto3" json:"genre,omitempty"`
	Md5         string  `protobuf:"bytes,17,opt,name=md5,proto3" json:"md5,omitempty"`
	AlbumArt    *string `protobuf:"bytes,18,opt,name=album_art,json=albumArt,proto3,oneof" json:"album_art,omitempty"`
	ArtistId    *string `protobuf:"bytes,19,opt,name=artist_id,json=artistId,proto3,oneof" json:"artist_id,omitempty"`
	AlbumId     *string `protobuf:"bytes,20,opt,name=album_id,json=albumId,proto3,oneof" json:"album_id,omitempty"`
	GenreId     *string `protobuf:"bytes,21,opt,name=genre_id,json=genreId,proto3,oneof" json:"genre_id,omitempty"`
	CreatedAt   string  `protobuf:"bytes,22,opt,name=created_at,json=createdAt,proto3" json:"created_at,omitempty"`
	UpdatedAt   string  `protobuf:"bytes,23,opt,name=updated_at,json=updatedAt,proto3" json:"updated_at,omitempty"`
}

func (x *Track) Reset() {
	*x = Track{}
	if protoimpl.UnsafeEnabled {
		mi := &file_rockbox_search_v1alpha1_track_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *Track) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*Track) ProtoMessage() {}

func (x *Track) ProtoReflect() protoreflect.Message {
	mi := &file_rockbox_search_v1alpha1_track_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use Track.ProtoReflect.Descriptor instead.
func (*Track) Descriptor() ([]byte, []int) {
	return file_rockbox_search_v1alpha1_track_proto_rawDescGZIP(), []int{0}
}

func (x *Track) GetId() string {
	if x != nil {
		return x.Id
	}
	return ""
}

func (x *Track) GetPath() string {
	if x != nil {
		return x.Path
	}
	return ""
}

func (x *Track) GetTitle() string {
	if x != nil {
		return x.Title
	}
	return ""
}

func (x *Track) GetArtist() string {
	if x != nil {
		return x.Artist
	}
	return ""
}

func (x *Track) GetAlbum() string {
	if x != nil {
		return x.Album
	}
	return ""
}

func (x *Track) GetAlbumArtist() string {
	if x != nil {
		return x.AlbumArtist
	}
	return ""
}

func (x *Track) GetBitrate() uint32 {
	if x != nil {
		return x.Bitrate
	}
	return 0
}

func (x *Track) GetComposer() string {
	if x != nil {
		return x.Composer
	}
	return ""
}

func (x *Track) GetDiscNumber() uint32 {
	if x != nil {
		return x.DiscNumber
	}
	return 0
}

func (x *Track) GetFilesize() uint32 {
	if x != nil {
		return x.Filesize
	}
	return 0
}

func (x *Track) GetFrequency() uint32 {
	if x != nil {
		return x.Frequency
	}
	return 0
}

func (x *Track) GetLength() uint32 {
	if x != nil {
		return x.Length
	}
	return 0
}

func (x *Track) GetTrackNumber() uint32 {
	if x != nil {
		return x.TrackNumber
	}
	return 0
}

func (x *Track) GetYear() uint32 {
	if x != nil {
		return x.Year
	}
	return 0
}

func (x *Track) GetYearString() string {
	if x != nil {
		return x.YearString
	}
	return ""
}

func (x *Track) GetGenre() string {
	if x != nil {
		return x.Genre
	}
	return ""
}

func (x *Track) GetMd5() string {
	if x != nil {
		return x.Md5
	}
	return ""
}

func (x *Track) GetAlbumArt() string {
	if x != nil && x.AlbumArt != nil {
		return *x.AlbumArt
	}
	return ""
}

func (x *Track) GetArtistId() string {
	if x != nil && x.ArtistId != nil {
		return *x.ArtistId
	}
	return ""
}

func (x *Track) GetAlbumId() string {
	if x != nil && x.AlbumId != nil {
		return *x.AlbumId
	}
	return ""
}

func (x *Track) GetGenreId() string {
	if x != nil && x.GenreId != nil {
		return *x.GenreId
	}
	return ""
}

func (x *Track) GetCreatedAt() string {
	if x != nil {
		return x.CreatedAt
	}
	return ""
}

func (x *Track) GetUpdatedAt() string {
	if x != nil {
		return x.UpdatedAt
	}
	return ""
}

type TrackList struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Tracks []*Track `protobuf:"bytes,1,rep,name=tracks,proto3" json:"tracks,omitempty"`
}

func (x *TrackList) Reset() {
	*x = TrackList{}
	if protoimpl.UnsafeEnabled {
		mi := &file_rockbox_search_v1alpha1_track_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *TrackList) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*TrackList) ProtoMessage() {}

func (x *TrackList) ProtoReflect() protoreflect.Message {
	mi := &file_rockbox_search_v1alpha1_track_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use TrackList.ProtoReflect.Descriptor instead.
func (*TrackList) Descriptor() ([]byte, []int) {
	return file_rockbox_search_v1alpha1_track_proto_rawDescGZIP(), []int{1}
}

func (x *TrackList) GetTracks() []*Track {
	if x != nil {
		return x.Tracks
	}
	return nil
}

var File_rockbox_search_v1alpha1_track_proto protoreflect.FileDescriptor

var file_rockbox_search_v1alpha1_track_proto_rawDesc = []byte{
	0x0a, 0x23, 0x72, 0x6f, 0x63, 0x6b, 0x62, 0x6f, 0x78, 0x2f, 0x73, 0x65, 0x61, 0x72, 0x63, 0x68,
	0x2f, 0x76, 0x31, 0x61, 0x6c, 0x70, 0x68, 0x61, 0x31, 0x2f, 0x74, 0x72, 0x61, 0x63, 0x6b, 0x2e,
	0x70, 0x72, 0x6f, 0x74, 0x6f, 0x12, 0x17, 0x72, 0x6f, 0x63, 0x6b, 0x62, 0x6f, 0x78, 0x2e, 0x73,
	0x65, 0x61, 0x72, 0x63, 0x68, 0x2e, 0x76, 0x31, 0x61, 0x6c, 0x70, 0x68, 0x61, 0x31, 0x22, 0xb3,
	0x05, 0x0a, 0x05, 0x54, 0x72, 0x61, 0x63, 0x6b, 0x12, 0x0e, 0x0a, 0x02, 0x69, 0x64, 0x18, 0x01,
	0x20, 0x01, 0x28, 0x09, 0x52, 0x02, 0x69, 0x64, 0x12, 0x12, 0x0a, 0x04, 0x70, 0x61, 0x74, 0x68,
	0x18, 0x02, 0x20, 0x01, 0x28, 0x09, 0x52, 0x04, 0x70, 0x61, 0x74, 0x68, 0x12, 0x14, 0x0a, 0x05,
	0x74, 0x69, 0x74, 0x6c, 0x65, 0x18, 0x03, 0x20, 0x01, 0x28, 0x09, 0x52, 0x05, 0x74, 0x69, 0x74,
	0x6c, 0x65, 0x12, 0x16, 0x0a, 0x06, 0x61, 0x72, 0x74, 0x69, 0x73, 0x74, 0x18, 0x04, 0x20, 0x01,
	0x28, 0x09, 0x52, 0x06, 0x61, 0x72, 0x74, 0x69, 0x73, 0x74, 0x12, 0x14, 0x0a, 0x05, 0x61, 0x6c,
	0x62, 0x75, 0x6d, 0x18, 0x05, 0x20, 0x01, 0x28, 0x09, 0x52, 0x05, 0x61, 0x6c, 0x62, 0x75, 0x6d,
	0x12, 0x21, 0x0a, 0x0c, 0x61, 0x6c, 0x62, 0x75, 0x6d, 0x5f, 0x61, 0x72, 0x74, 0x69, 0x73, 0x74,
	0x18, 0x06, 0x20, 0x01, 0x28, 0x09, 0x52, 0x0b, 0x61, 0x6c, 0x62, 0x75, 0x6d, 0x41, 0x72, 0x74,
	0x69, 0x73, 0x74, 0x12, 0x18, 0x0a, 0x07, 0x62, 0x69, 0x74, 0x72, 0x61, 0x74, 0x65, 0x18, 0x07,
	0x20, 0x01, 0x28, 0x0d, 0x52, 0x07, 0x62, 0x69, 0x74, 0x72, 0x61, 0x74, 0x65, 0x12, 0x1a, 0x0a,
	0x08, 0x63, 0x6f, 0x6d, 0x70, 0x6f, 0x73, 0x65, 0x72, 0x18, 0x08, 0x20, 0x01, 0x28, 0x09, 0x52,
	0x08, 0x63, 0x6f, 0x6d, 0x70, 0x6f, 0x73, 0x65, 0x72, 0x12, 0x1f, 0x0a, 0x0b, 0x64, 0x69, 0x73,
	0x63, 0x5f, 0x6e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x18, 0x09, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x0a,
	0x64, 0x69, 0x73, 0x63, 0x4e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x12, 0x1a, 0x0a, 0x08, 0x66, 0x69,
	0x6c, 0x65, 0x73, 0x69, 0x7a, 0x65, 0x18, 0x0a, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x08, 0x66, 0x69,
	0x6c, 0x65, 0x73, 0x69, 0x7a, 0x65, 0x12, 0x1c, 0x0a, 0x09, 0x66, 0x72, 0x65, 0x71, 0x75, 0x65,
	0x6e, 0x63, 0x79, 0x18, 0x0b, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x09, 0x66, 0x72, 0x65, 0x71, 0x75,
	0x65, 0x6e, 0x63, 0x79, 0x12, 0x16, 0x0a, 0x06, 0x6c, 0x65, 0x6e, 0x67, 0x74, 0x68, 0x18, 0x0c,
	0x20, 0x01, 0x28, 0x0d, 0x52, 0x06, 0x6c, 0x65, 0x6e, 0x67, 0x74, 0x68, 0x12, 0x21, 0x0a, 0x0c,
	0x74, 0x72, 0x61, 0x63, 0x6b, 0x5f, 0x6e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x18, 0x0d, 0x20, 0x01,
	0x28, 0x0d, 0x52, 0x0b, 0x74, 0x72, 0x61, 0x63, 0x6b, 0x4e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x12,
	0x12, 0x0a, 0x04, 0x79, 0x65, 0x61, 0x72, 0x18, 0x0e, 0x20, 0x01, 0x28, 0x0d, 0x52, 0x04, 0x79,
	0x65, 0x61, 0x72, 0x12, 0x1f, 0x0a, 0x0b, 0x79, 0x65, 0x61, 0x72, 0x5f, 0x73, 0x74, 0x72, 0x69,
	0x6e, 0x67, 0x18, 0x0f, 0x20, 0x01, 0x28, 0x09, 0x52, 0x0a, 0x79, 0x65, 0x61, 0x72, 0x53, 0x74,
	0x72, 0x69, 0x6e, 0x67, 0x12, 0x14, 0x0a, 0x05, 0x67, 0x65, 0x6e, 0x72, 0x65, 0x18, 0x10, 0x20,
	0x01, 0x28, 0x09, 0x52, 0x05, 0x67, 0x65, 0x6e, 0x72, 0x65, 0x12, 0x10, 0x0a, 0x03, 0x6d, 0x64,
	0x35, 0x18, 0x11, 0x20, 0x01, 0x28, 0x09, 0x52, 0x03, 0x6d, 0x64, 0x35, 0x12, 0x20, 0x0a, 0x09,
	0x61, 0x6c, 0x62, 0x75, 0x6d, 0x5f, 0x61, 0x72, 0x74, 0x18, 0x12, 0x20, 0x01, 0x28, 0x09, 0x48,
	0x00, 0x52, 0x08, 0x61, 0x6c, 0x62, 0x75, 0x6d, 0x41, 0x72, 0x74, 0x88, 0x01, 0x01, 0x12, 0x20,
	0x0a, 0x09, 0x61, 0x72, 0x74, 0x69, 0x73, 0x74, 0x5f, 0x69, 0x64, 0x18, 0x13, 0x20, 0x01, 0x28,
	0x09, 0x48, 0x01, 0x52, 0x08, 0x61, 0x72, 0x74, 0x69, 0x73, 0x74, 0x49, 0x64, 0x88, 0x01, 0x01,
	0x12, 0x1e, 0x0a, 0x08, 0x61, 0x6c, 0x62, 0x75, 0x6d, 0x5f, 0x69, 0x64, 0x18, 0x14, 0x20, 0x01,
	0x28, 0x09, 0x48, 0x02, 0x52, 0x07, 0x61, 0x6c, 0x62, 0x75, 0x6d, 0x49, 0x64, 0x88, 0x01, 0x01,
	0x12, 0x1e, 0x0a, 0x08, 0x67, 0x65, 0x6e, 0x72, 0x65, 0x5f, 0x69, 0x64, 0x18, 0x15, 0x20, 0x01,
	0x28, 0x09, 0x48, 0x03, 0x52, 0x07, 0x67, 0x65, 0x6e, 0x72, 0x65, 0x49, 0x64, 0x88, 0x01, 0x01,
	0x12, 0x1d, 0x0a, 0x0a, 0x63, 0x72, 0x65, 0x61, 0x74, 0x65, 0x64, 0x5f, 0x61, 0x74, 0x18, 0x16,
	0x20, 0x01, 0x28, 0x09, 0x52, 0x09, 0x63, 0x72, 0x65, 0x61, 0x74, 0x65, 0x64, 0x41, 0x74, 0x12,
	0x1d, 0x0a, 0x0a, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x64, 0x5f, 0x61, 0x74, 0x18, 0x17, 0x20,
	0x01, 0x28, 0x09, 0x52, 0x09, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x64, 0x41, 0x74, 0x42, 0x0c,
	0x0a, 0x0a, 0x5f, 0x61, 0x6c, 0x62, 0x75, 0x6d, 0x5f, 0x61, 0x72, 0x74, 0x42, 0x0c, 0x0a, 0x0a,
	0x5f, 0x61, 0x72, 0x74, 0x69, 0x73, 0x74, 0x5f, 0x69, 0x64, 0x42, 0x0b, 0x0a, 0x09, 0x5f, 0x61,
	0x6c, 0x62, 0x75, 0x6d, 0x5f, 0x69, 0x64, 0x42, 0x0b, 0x0a, 0x09, 0x5f, 0x67, 0x65, 0x6e, 0x72,
	0x65, 0x5f, 0x69, 0x64, 0x22, 0x43, 0x0a, 0x09, 0x54, 0x72, 0x61, 0x63, 0x6b, 0x4c, 0x69, 0x73,
	0x74, 0x12, 0x36, 0x0a, 0x06, 0x74, 0x72, 0x61, 0x63, 0x6b, 0x73, 0x18, 0x01, 0x20, 0x03, 0x28,
	0x0b, 0x32, 0x1e, 0x2e, 0x72, 0x6f, 0x63, 0x6b, 0x62, 0x6f, 0x78, 0x2e, 0x73, 0x65, 0x61, 0x72,
	0x63, 0x68, 0x2e, 0x76, 0x31, 0x61, 0x6c, 0x70, 0x68, 0x61, 0x31, 0x2e, 0x54, 0x72, 0x61, 0x63,
	0x6b, 0x52, 0x06, 0x74, 0x72, 0x61, 0x63, 0x6b, 0x73, 0x42, 0x3e, 0x5a, 0x3c, 0x67, 0x69, 0x74,
	0x68, 0x75, 0x62, 0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x74, 0x73, 0x69, 0x72, 0x79, 0x73, 0x6e, 0x64,
	0x72, 0x2f, 0x72, 0x6f, 0x63, 0x6b, 0x62, 0x6f, 0x78, 0x2d, 0x7a, 0x69, 0x67, 0x2f, 0x67, 0x65,
	0x6e, 0x2f, 0x72, 0x6f, 0x63, 0x6b, 0x62, 0x6f, 0x78, 0x2f, 0x73, 0x65, 0x61, 0x72, 0x63, 0x68,
	0x2f, 0x76, 0x31, 0x61, 0x6c, 0x70, 0x68, 0x61, 0x31, 0x62, 0x06, 0x70, 0x72, 0x6f, 0x74, 0x6f,
	0x33,
}

var (
	file_rockbox_search_v1alpha1_track_proto_rawDescOnce sync.Once
	file_rockbox_search_v1alpha1_track_proto_rawDescData = file_rockbox_search_v1alpha1_track_proto_rawDesc
)

func file_rockbox_search_v1alpha1_track_proto_rawDescGZIP() []byte {
	file_rockbox_search_v1alpha1_track_proto_rawDescOnce.Do(func() {
		file_rockbox_search_v1alpha1_track_proto_rawDescData = protoimpl.X.CompressGZIP(file_rockbox_search_v1alpha1_track_proto_rawDescData)
	})
	return file_rockbox_search_v1alpha1_track_proto_rawDescData
}

var file_rockbox_search_v1alpha1_track_proto_msgTypes = make([]protoimpl.MessageInfo, 2)
var file_rockbox_search_v1alpha1_track_proto_goTypes = []interface{}{
	(*Track)(nil),     // 0: rockbox.search.v1alpha1.Track
	(*TrackList)(nil), // 1: rockbox.search.v1alpha1.TrackList
}
var file_rockbox_search_v1alpha1_track_proto_depIdxs = []int32{
	0, // 0: rockbox.search.v1alpha1.TrackList.tracks:type_name -> rockbox.search.v1alpha1.Track
	1, // [1:1] is the sub-list for method output_type
	1, // [1:1] is the sub-list for method input_type
	1, // [1:1] is the sub-list for extension type_name
	1, // [1:1] is the sub-list for extension extendee
	0, // [0:1] is the sub-list for field type_name
}

func init() { file_rockbox_search_v1alpha1_track_proto_init() }
func file_rockbox_search_v1alpha1_track_proto_init() {
	if File_rockbox_search_v1alpha1_track_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_rockbox_search_v1alpha1_track_proto_msgTypes[0].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*Track); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_rockbox_search_v1alpha1_track_proto_msgTypes[1].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*TrackList); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
	}
	file_rockbox_search_v1alpha1_track_proto_msgTypes[0].OneofWrappers = []interface{}{}
	type x struct{}
	out := protoimpl.TypeBuilder{
		File: protoimpl.DescBuilder{
			GoPackagePath: reflect.TypeOf(x{}).PkgPath(),
			RawDescriptor: file_rockbox_search_v1alpha1_track_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   2,
			NumExtensions: 0,
			NumServices:   0,
		},
		GoTypes:           file_rockbox_search_v1alpha1_track_proto_goTypes,
		DependencyIndexes: file_rockbox_search_v1alpha1_track_proto_depIdxs,
		MessageInfos:      file_rockbox_search_v1alpha1_track_proto_msgTypes,
	}.Build()
	File_rockbox_search_v1alpha1_track_proto = out.File
	file_rockbox_search_v1alpha1_track_proto_rawDesc = nil
	file_rockbox_search_v1alpha1_track_proto_goTypes = nil
	file_rockbox_search_v1alpha1_track_proto_depIdxs = nil
}
