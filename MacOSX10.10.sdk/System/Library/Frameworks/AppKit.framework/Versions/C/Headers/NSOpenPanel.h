/*
    NSOpenPanel.h
    Application Kit
    Copyright (c) 1994-2014, Apple Inc.
    All rights reserved.
*/

#import <AppKit/NSSavePanel.h>
@class NSArray;
@class NSString;
@class NSWindow;

@interface NSOpenPanel : NSSavePanel {
@private
    char _reservedOpenPanel[4];
    void *_privateOpenPanel;
}

/* Creates a new instance of the NSOpenPanel. This class is not a singleton. 
 */
+ (NSOpenPanel *)openPanel;

@property (readonly, copy) NSArray *URLs;

@property BOOL resolvesAliases;

@property BOOL canChooseDirectories;

@property BOOL allowsMultipleSelection;

@property BOOL canChooseFiles;

/* Controls how the receiver responds to ubiquitous documents with conflicting versions. If YES, then when the user attempts to open one or more documents with conflicts, the receiver will first display conflict resolution UI, requiring the user to resolve those conflicts before the documents can be opened. If NO, then the receiver does nothing in response to conflicts, allowing your application to handle them. The default value is YES, except for applications linked against the 10.9 SDK or earlier that have adopted iCloud by specifying a ubiquitous container identifier entitlement.
 
To provide the ideal user experience, you should set this property to NO and do conflict detection and resolution (using NSURLUbiquitousItemHasUnresolvedConflictsKey and NSFileVersion) in the context of your application, instead of relying on the open panel to do it.
*/
@property BOOL canResolveUbiquitousConflicts NS_AVAILABLE_MAC(10_10);

/* Controls how the receiver responds to ubiquitous documents that aren't yet fully downloaded locally. If YES, then the receiver will disallow opening non-local ubiquitous files. Also, if the user attempts to select a non-local file, the receiver will trigger or reprioritize downloading for that file so that it can be opened as soon as possible. If NO, then the receiver will allow the user to select and open non-local files, giving your application responsibility for downloading and reporting progress. The default value is YES, except for applications linked against the 10.9 SDK or earlier that have adopted iCloud by specifying a ubiquitous container identifier entitlement.
 
To provide the ideal user experience, you should set this property to NO and download the file's contents (with NSFileCoordinator) and show downloading progress (with NSProgress or NSMetadataQuery) in the context of your application, instead of relying on the open panel to do it.
*/
@property BOOL canDownloadUbiquitousContents NS_AVAILABLE_MAC(10_10);

@end

@interface NSOpenPanel (NSDeprecated)

/* Use URLs instead.
 */
- (NSArray *)filenames NS_DEPRECATED_MAC(10_0, 10_6);

/* Use -beginSheetModalForWindow:completionHandler: instead.
    Set the -directoryURL property instead of passing in a 'path'.
    Set the -allowedFileTypes property instead of passing in the 'fileTypes'.
 */
- (void)beginSheetForDirectory:(NSString *)path file:(NSString *)name types:(NSArray *)fileTypes modalForWindow:(NSWindow *)docWindow modalDelegate:(id)delegate didEndSelector:(SEL)didEndSelector contextInfo:(void *)contextInfo NS_DEPRECATED_MAC(10_0, 10_6);

/* Use -beginWithCompletionHandler: instead. 
    Set the -directoryURL property instead of passing in a 'path'.
    Set the -allowedFileTypes property instead of passing in the 'fileTypes'.
 */
- (void)beginForDirectory:(NSString *)path file:(NSString *)name types:(NSArray *)fileTypes modelessDelegate:(id)delegate didEndSelector:(SEL)didEndSelector contextInfo:(void *)contextInfo  NS_DEPRECATED_MAC(10_0, 10_6);

/* Use -runModal instead. 
    Set the -directoryURL property instead of passing in a 'path'.
    Set the -allowedFileTypes property instead of passing in the 'fileTypes'.
 */
- (NSInteger)runModalForDirectory:(NSString *)path file:(NSString *)name types:(NSArray *)fileTypes NS_DEPRECATED_MAC(10_0, 10_6);

/* Use -runModal instead. 
    Set the -allowedFileTypes property instead of passing in the 'fileTypes'.
 */
- (NSInteger)runModalForTypes:(NSArray *)fileTypes NS_DEPRECATED_MAC(10_0, 10_6);

@end
